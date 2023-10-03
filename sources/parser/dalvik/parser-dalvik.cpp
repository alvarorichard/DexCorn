#include "parser/dalvik/parser-dalvik.hpp"

#include <iostream>

namespace Parser
{
    Dalvik::Dalvik(const std::string &file) : m_dex(LIEF::DEX::Parser::parse(file))
    {
    }

    Dalvik::~Dalvik()
    {
    }

    LIEF::DEX::File *Dalvik::getDexFile()
    {
        return m_dex.get();
    }

    Parser::Dalvik::method_infos_T Dalvik::setMethodInfo(LIEF::DEX::Method method)
    {
        method_T.name = method.name();
        method_T.is_virtual = method.is_virtual();
        method_T.returned_type = method.prototype()->return_type()->pretty_name(method.prototype()->return_type()->primitive());
        for (auto &it : method.prototype()->parameters_type())
        {
            method_T.parameters_type += it.pretty_name(it.primitive());
        }
        method_T.underlying_array_type = method.prototype()->parameters_type()->underlying_array_type();
        method_T.has_class = method.has_class();
        method_T.cls = setMethodClassInfo(method.cls());
        method_T.bytecode = method.bytecode();
        method_T.code_offset = method.code_offset();

        return method_T;
    }

    Parser::Dalvik::method_class_infos_T Dalvik::setMethodClassInfo(LIEF::DEX::Class *method_class)
    {
        method_class_T.fullname = method_class->fullname();
        for(auto &it : method_class->fields())
        {
            method_class_T.fields_name += it.name();
        }
        
        method_class_T.package_name = method_class->package_name();
        method_class_T.pretty_name = method_class->pretty_name();
        
        return method_class_T;
    }

    void Dalvik::getAllMethods()
    {
        for (auto &class_ : m_dex->classes())
        {
            for (auto &methods_ : class_.methods())
            {
                std::cout << class_.name() << ":" << methods_.name() << "(";
                for (auto &parameters_ : methods_.prototype()->parameters_type())
                {
                    std::cout << parameters_.underlying_array_type()
                              << parameters_.pretty_name(parameters_.primitive());
                }
                std::cout << ")" << methods_.prototype()->return_type()->pretty_name(methods_.prototype()->return_type()->primitive()) << std::endl;
            }
        }
    }
}
