#include "UmlGenerator.h"

void UmlGenerator::generate(){
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file\n";
        return;
    }
    
    outputFile << "\\documentclass{article}\n";
    outputFile << "\\usepackage[pdftex,active,tightpage]{preview}\n";
    outputFile << "\\usepackage{tikz}\n";
    outputFile << "\\usepackage{pgf-umlcd}\n";
    outputFile << "\\usepackage{listings}\n";
    outputFile << "\\begin{document}\n";
    outputFile << "\\begin{preview}\n";
    outputFile << "\\renewcommand {\\umltextcolor}{"<<colors.getTextColor()<<"}\n";
    outputFile << "\\renewcommand {\\umlfillcolor}{"<<colors.getFillColor()<<"}\n";
    outputFile << "\\renewcommand {\\umldrawcolor}{"<<colors.getDrawColor()<<"}\n";
    outputFile << "\\begin{tikzpicture}\n";
    if (flags & GenFlags::GRID)
        outputFile << "[show background grid]";

    int x = 0;
    int y = 0;
    
    outputFile << "\\begin{class}[ text width =16 cm ]{" << classTree.get_name() << "}";
    outputFile << "{" << x << "," << y << "}\n";
    x+=10;


    if ((flags & GenFlags::FIELD)==GenFlags::FIELD){
        genFields(classTree);
    }

    if ((flags & GenFlags::METHOD)==GenFlags::METHOD){
        genMethods(classTree);
    }
    
    outputFile << "\\end{class}\n";

    outputFile << "\\end{tikzpicture}\n";
    outputFile << "\\end{preview}\n";
    outputFile << "\\end{document}\n";
}

void UmlGenerator::genFields(const ClassTree &e){
    const auto &fields = e.get_fields();
    for (const auto &f: fields){
        outputFile << "\\attribute{\\lstinline|";
        if ((flags & GenFlags::ACC_SPEC)==GenFlags::ACC_SPEC){
            if (f.get_acc_spec() == "public")
                outputFile << "+ ";
            else if (f.get_acc_spec() == "private")
                outputFile << "- ";
            
            else
                outputFile << f.get_acc_spec();
            
        }
    
        
        if ((flags & GenFlags::TYPE)== GenFlags::TYPE)
            outputFile << f.get_type() << " ";
        outputFile << f.get_name();
        outputFile << "|}\n";
    }

}

void UmlGenerator::genMethods(const ClassTree &e){
    const auto &methods = e.get_methods();
    for (const auto &m: methods){
        outputFile << "\\operation{\\lstinline|";
        if ((flags & GenFlags::ACC_SPEC)==GenFlags::ACC_SPEC){
            if (m.get_acc_spec() == "public")
                outputFile << "+ ";
            else if (m.get_acc_spec() == "private")
                outputFile << "- ";
            
            else
                outputFile << m.get_acc_spec();
            
        }
        
        if (flags & GenFlags::TYPE)
            outputFile << m.get_type() << " ";
        outputFile << m.get_name();
        outputFile << "(";
        if (flags & GenFlags::METHOD_ARG){
            auto args = m.get_arguments();
            for (auto a: args){
                outputFile << a << " ";
            }
            outputFile << ")";
            outputFile << "|}\n";
        }
    }
}


