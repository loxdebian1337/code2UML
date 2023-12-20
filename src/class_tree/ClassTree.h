#pragma once

#include <string>
#include <vector>
#include <memory>


class Parser;

class ClassTree final
{
public:

    class field
    {
    public:
        field( const std::string& _acc_spec, const std::string& _type, const std::string& _name )
                : acc_spec( _acc_spec )
                , type( _type )
                , name( _name )
        {
        }

        std::string get_acc_spec() const { return acc_spec; }
        std::string get_type() const { return type; }
        std::string get_name() const { return name; }

    private:
        std::string acc_spec;
        std::string type;
        std::string name;
    };

    class method
    {
    public:
        method( const std::string& _acc_spec, const std::string& _type, const std::string& _name, const std::vector< std::string >& _arguments )
                : acc_spec( _acc_spec )
                , type( _type )
                , name( _name )
                , arguments( _arguments )
        {
        }

        std::string get_acc_spec() const { return acc_spec; }
        std::string get_type() const { return type; }
        std::string get_name() const { return name; }
        std::vector< std::string > get_arguments() const { return arguments; }

    private:
        std::string acc_spec;
        std::string type;
        std::string name;
        std::vector< std::string > arguments;
    };

    ClassTree() = default;
    ClassTree(Parser &);

    std::string get_name() const { return name; }
    std::vector< std::shared_ptr< ClassTree>> get_parents() const { return parents; }
    std::vector< ClassTree::field > get_fields() const { return fields; }
    std::vector< ClassTree::method > get_methods() const { return methods; }

    void set_name( const std::string& _name ) { name = _name; }
    void set_parents( const std::vector< std::shared_ptr< ClassTree>>& _parents ) { parents = _parents; }
    void set_fields( const std::vector< ClassTree::field >& _fields ) { fields = _fields; }
    void set_methods( const std::vector< ClassTree::method >& _methods ) { methods = _methods; }

private:
    std::string name;
    std::vector< std::shared_ptr< ClassTree>> parents;
    std::vector< ClassTree::field > fields;
    std::vector< ClassTree::method > methods;

};
