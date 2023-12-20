#include "MyCppParser.h"

#include <cppparser.h>

#include <map>

MyCppParser::MyCppParser( const std::string& filename )
{
    std::vector< ClassTree::field > _fields;
    std::vector< ClassTree::method > _methods;

    std::map< CppAccessType, std::string > acc_string{
            { CppAccessType::kPublic,    "public" },
            { CppAccessType::kProtected, "protected" },
            { CppAccessType::kPrivate,   "private" } };

    CppParser parser;
    const auto ast = parser.parseFile( filename );

    const auto& ast_members = ast->members();
    for( const auto& ast_member : ast_members )
    {
        if( ast_member->objType_ == CppObjType::kCompound )
        {
            CppCompoundEPtr class_ = ast_member;
            name_ = class_->name();

            for( const auto& field : class_->members() )
            {
                if( field->objType_ == CppObjType::kVar )
                {
                    CppVarEPtr field_ptr( field );
                    ClassTree::field _field( acc_string[ field_ptr->accessType_ ],
                                             field_ptr->varType()->baseType(),
                                             field_ptr->name()
                    );

                    fields_.push_back( _field );
                }
            }


            for( const auto& method : class_->members() )
            {
                if( method->objType_ == CppObjType::kFunction )
                {
                    CppFunctionEPtr method_ptr( method );

                    std::vector< std::string > _params;
                    if( method_ptr->hasParams() )
                    {
                        for( const auto& param : *method_ptr->params() )
                        {
                            _params.push_back( ( ( CppVarEPtr ) param )->varType()->baseType() );
                        }
                    }
                    ClassTree::method _method( acc_string[ method_ptr->accessType_ ],
                                               method_ptr->retType_->baseType(),
                                               method_ptr->name_,
                                               _params
                    );

                    method_.push_back( _method );
                }
            }
        }
    }
}

std::string MyCppParser::name() {
    return name_;
}

std::vector<std::shared_ptr<ClassTree>> MyCppParser::parents() {
    return parents_;
}

std::vector<ClassTree::field> MyCppParser::fields()  {
    return fields_;
}

std::vector<ClassTree::method> MyCppParser::methods() {
    return method_;
}
