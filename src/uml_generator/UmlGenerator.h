#pragma once

#include <string>
#include <set>
#include <memory>
#include <fstream>
#include <iostream>
#include <ClassTree.h>

enum GenFlags : int{
    GRID        = 0,

    METHOD      = 1 << 0,
    FIELD       = 1 << 1,
    
    ACC_SPEC    = 1 << 2,
    TYPE_SPEC   = 1 << 3,
    TYPE        = 1 << 4,
    METHOD_ARG  = 1 << 5,
};



class UmlGenerator {
private:
    class Colors{
        private:
            std::string umlTextColor = "black";
            std::string umlFillColor = "white";
            std::string umlDrawColor = "black";
        public:
            // void setTextColour();
            // void setFillColour();
            // void setDrawColour();

            std::string getTextColor() const { return umlTextColor; }
            std::string getFillColor() const { return umlFillColor; }
            std::string getDrawColor() const { return umlDrawColor; }

        };
public:
      UmlGenerator(const ClassTree& _class, const std::string& _outputFile, const GenFlags& _flags)
        : classTree(_class), outputFile(_outputFile), flags(_flags) {}
    void generate();

private:
    ClassTree classTree;
    GenFlags flags;
    std::ofstream outputFile;

    void genFields(const ClassTree &e);
    void genMethods(const ClassTree &e);

public:
    Colors colors;
};
