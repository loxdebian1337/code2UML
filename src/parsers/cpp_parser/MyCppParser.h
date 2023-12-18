#include <Parser.h>

class MyCppParser final : public Parser {
public:
  MyCppParser(const std::string &); 

  virtual std::string name() override;
  virtual std::set<std::shared_ptr<ClassTree>> parents() override{};
  virtual std::set<ClassTree::field> fields() override{};
  virtual std::set<ClassTree::method> method() override{};

private:
  
};
