#include "MyCppParser.h"

#include <cppparser.h>

#include <iostream>

MyCppParser::MyCppParser(const std::string &fileName) {
  CppParser parser;
  const auto ast = parser.parseFile(fileName.c_str());

  for(CppIncludeEPtr a : ast->members()) {
    std::cout << a->name_ << '\n';
  }

}

std::string MyCppParser::name() {
  
}

