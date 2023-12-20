#include "ClassTree.h"
#include <Parser.h>

ClassTree::ClassTree( Parser& parser )
{
    name = parser.name();
    fields = parser.fields();
    methods = parser.methods();
}