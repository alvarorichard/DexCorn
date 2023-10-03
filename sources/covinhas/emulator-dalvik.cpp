#include "covinhas/emulator-dalvik.hpp"

#include <fmt/format.h>
#include <iostream>

namespace Covinhas
{
        Dalvik::Dalvik(const std::string file) : m_emulator(UC_ARCH_X86, UC_MODE_64), m_dalvik(file)
        {
                configureEmulator();
        }

        Dalvik::~Dalvik()
        {
        }

        const std::uint64_t Dalvik::findOffsetMethod(const std::string method_name, const std::string class_name)
        {
                for (unsigned i = 0; i < m_dalvik.getDexFile()->methods().size(); i++)
                {
                        if (m_dalvik.getDexFile()->methods()[i].name() == method_name && 
                                                m_dalvik.getDexFile()->methods()[i].cls()->name() == class_name)
                        {
                                return m_dalvik.getDexFile()->methods()[i].code_offset();
                        }
                }

                const std::string error = fmt::format("[{}] Method {}:{} not found", __FUNCTION__, class_name, method_name);
                throw std::runtime_error(error);
        }

        Parser::Dalvik::method_infos_T Dalvik::setMethodToEmulator(const std::uint64_t offset, const std::string class_name)
        {
                for (unsigned i = 0; i < m_dalvik.getDexFile()->methods().size(); i++)
                {
                        if (m_dalvik.getDexFile()->methods()[i].code_offset() == offset && 
                                                m_dalvik.getDexFile()->methods()[i].cls()->name() == class_name)
                        {
                                Parser::Dalvik::method_infos_T function = m_dalvik.setMethodInfo(m_dalvik.getDexFile()->methods()[i]);
                                return function;
                        }
                }

                const std::string error = fmt::format("[{}] Method {}:{} not found", __FUNCTION__, class_name, offset);
                throw std::runtime_error(error);
        }

        Parser::Dalvik::method_infos_T Dalvik::setMethodToEmulator(const std::string method_name, const std::string class_name)
        {
                for (unsigned i = 0; i < m_dalvik.getDexFile()->methods().size(); i++)
                {
                        if (m_dalvik.getDexFile()->methods()[i].name() == method_name && 
                                                m_dalvik.getDexFile()->methods()[i].cls()->name() == class_name)
                        {
                                Parser::Dalvik::method_infos_T function = m_dalvik.setMethodInfo(m_dalvik.getDexFile()->methods()[i]);
                                return function;
                        }
                }

                const std::string error = fmt::format("[{}] Method {}:{} not found", __FUNCTION__, class_name, method_name);
                throw std::runtime_error(error);
        }

        
        
        void Dalvik::startEmulator()
        {
                // m_emulator.startEmulator();
        }

        void Dalvik::configureEmulator()
        {
                m_emulator.memMap(2 * 1024 * 1024, UC_PROT_ALL);
        }
}
