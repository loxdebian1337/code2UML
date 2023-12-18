#pragma once 

#include <string>
#include <set>
#include <memory>

class ClassTree final {
public:

  class field {
  public:
    std::string get_acc_spec() const { return acc_spec; }
    std::string get_type_spec() const { return type_spec; }
    std::string get_type() const { return type; }
    std::string get_name() const { return name; }

  private:
    std::string acc_spec;
    std::string type_spec;
    std::string type;
    std::string name;
  };

  class method {
  public:
    std::string get_acc_spec() const { return acc_spec; }
    std::string get_type_spec() const { return type_spec; }
    std::string get_type() const { return type; }
    std::string get_name() const { return name; }
    std::set<std::string> get_arguments() const { return arguments; }

  private: 
    std::string acc_spec;
    std::string type_spec;
    std::string type;
    std::string name;
    std::set<std::string> arguments;
  };

  std::string get_name() const { return name; }
  
  std::set<std::shared_ptr<ClassTree>> get_parents() const { return parents; }
  std::set<ClassTree::field> get_fields() const { return fields; }
  std::set<ClassTree::method> get_methods() const { return methods; }

  void set_name(const std::string &_name) { name = _name; }
  void set_parents(const std::set<std::shared_ptr<ClassTree>> &_parents) { parents = _parents; }
  void set_fields(const std::set<ClassTree::field> &_fields) { fields = _fields; }
  void set_methods(const std::set<ClassTree::method> &_methods) { methods = _methods; }
private:
  std::string name;
  std::set<std::shared_ptr<ClassTree>> parents;
  std::set<ClassTree::field> fields;
  std::set<ClassTree::method> methods;

};
