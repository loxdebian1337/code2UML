#pragma once 

#include <fstream>
#include <memory>

#include <ClassTree.h>

class Parser {
public:
  
  virtual std::string name() = 0;
  virtual std::set<std::shared_ptr<ClassTree>> parents() = 0;
  virtual std::set<ClassTree::field> fields() = 0;
  virtual std::set<ClassTree::method> method() = 0;

  
};
