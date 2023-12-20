#pragma once

#include <fstream>
#include <memory>

#include <ClassTree.h>

class Parser
{
public:

    virtual std::string name() = 0;
    virtual std::vector< std::shared_ptr< ClassTree>> parents() = 0;
    virtual std::vector< ClassTree::field > fields() = 0;
    virtual std::vector< ClassTree::method > methods() = 0;

};
