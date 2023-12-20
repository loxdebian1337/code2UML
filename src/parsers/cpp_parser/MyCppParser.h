#include <Parser.h>

class MyCppParser final : public Parser
{
public:
    MyCppParser( const std::string& );

    virtual std::string name() override;
    virtual std::vector< std::shared_ptr< ClassTree>> parents() override;
    virtual std::vector< ClassTree::field > fields() override;
    virtual std::vector< ClassTree::method > methods() override;

private:
    std::string name_;
    std::vector< std::shared_ptr< ClassTree>> parents_{};
    std::vector< ClassTree::field > fields_;
    std::vector< ClassTree::method > method_;
};
