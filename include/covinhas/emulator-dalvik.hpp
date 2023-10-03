#include "emulator/emulator-unicorn.hpp"
#include "parser/dalvik/parser-dalvik.hpp"

#include <string>

namespace Covinhas 
{
    class Dalvik
    {
        public:
            Dalvik(const std::string file);
            ~Dalvik();
            
            [[nodiscard]] Parser::Dalvik::method_infos_T setMethodToEmulator(const std::uint64_t offset, const std::string class_name);
            [[nodiscard]] Parser::Dalvik::method_infos_T setMethodToEmulator(const std::string method_name, const std::string class_name);
            const std::uint64_t findOffsetMethod(const std::string method_name, const std::string class_name);
            void startEmulator();
            

        private:
            Emulator::Unicorn m_emulator;
            Parser::Dalvik m_dalvik;

            void configureEmulator();
    };
}