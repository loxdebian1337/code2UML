#include <ClassTree.h>
#include <cpp_parser/MyCppParser.h>

#include <iostream>

int main () {
  MyCppParser cpp_parser("TestClass.h");

  ClassTree ast(cpp_parser);

  std::cout << ast.get_name() << std::endl;
  std::cout << ast.get_methods().size() << std::endl;

}
