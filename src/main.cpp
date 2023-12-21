#include <ClassTree.h>
#include <cpp_parser/MyCppParser.h>
#include <UmlGenerator.h>
#include <set>
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <cstdlib>

int main(int argc, char *argv[]) {
    GenFlags flags = static_cast<GenFlags>(~0);
    std::string outfile="";
    std::string infile="";

    int option;
    struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"in_file", required_argument, 0, 'i'},
        {"out_file", required_argument, 0, 'o'},

        {"nomethods",no_argument,0,'m'},
        {"nofields",no_argument,0,'f'},
        {"grid",no_argument,0,'g'},
        {"acc_spec",no_argument,0,'s'},
        {"type",no_argument,0,'t'},
        {"method_arg", no_argument, 0, 'a'},

        {0, 0, 0, 0}
    };

    while ((option = getopt_long(argc, argv, "hi:o:mfsgta", long_options, NULL)) != -1) {  
        switch (option) {
            case 'h':
                printf("Help message\n");
                return 0;
            case 'i':
                infile = optarg;
                break;
            case 'o':
                outfile = optarg;
                break;
            case 'm':
                flags = static_cast<GenFlags>(flags & ~(GenFlags::METHOD));
                break;
            case 'f':
                flags = static_cast<GenFlags>(flags & ~(GenFlags::FIELD));
                break;
            case 'g':
                flags = static_cast<GenFlags>(flags & ~(GenFlags::GRID));
                break;
            case 's':
                flags = static_cast<GenFlags>(flags & ~(GenFlags::ACC_SPEC));
                break;
            case 't':
                flags = static_cast<GenFlags>(flags & ~(GenFlags::TYPE));
                break;
            case 'a':
                flags = static_cast<GenFlags>(flags & ~(GenFlags::METHOD_ARG));
                break;
            case '?':
                fprintf(stderr, "Unknown option: %c\n", optopt);
                return -1;
            default:
                fprintf(stderr, "Error parsing options\n");
                return -1;
        }
    }


    if (infile == ""){
        std::cout<<"No file provided, try -h for help\n";
    }

    if (outfile == ""){
        outfile = infile + ".tex";
    }

    MyCppParser cpp_parser(infile);
    ClassTree ast(cpp_parser);
    
    UmlGenerator umlgen(ast, outfile, flags);
    umlgen.generate();

    return 0;
}
