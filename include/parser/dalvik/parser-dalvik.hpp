#pragma once

#include <string>
#include <LIEF/LIEF.hpp>

namespace Parser
{
    class Dalvik
    {
    private:
        std::unique_ptr<LIEF::DEX::File> m_dex;

    public:
        Dalvik(const std::string &file);
        ~Dalvik();

        struct method_class_infos_T
        {
            std::string fullname;
            std::string fields_name;
            std::string package_name;
            std::string pretty_name;

        } method_class_T;

        struct method_infos_T
        {
            std::string returned_type;
            std::string parameters_type;
            LIEF::DEX::Type underlying_array_type;
            std::string name;
            bool is_virtual;
            bool has_class;
            Parser::Dalvik::method_class_infos_T cls;
            LIEF::DEX::Method::bytecode_t bytecode;
            std::uint64_t code_offset;

        } method_T;

        Parser::Dalvik::method_infos_T setMethodInfo(LIEF::DEX::Method method);
        Parser::Dalvik::method_class_infos_T setMethodClassInfo(LIEF::DEX::Class *method_class);
        void getAllMethods();

        LIEF::DEX::File *getDexFile();
    };
};