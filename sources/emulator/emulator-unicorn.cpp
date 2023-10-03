#include <fmt/format.h>
#include <stdexcept>
#include "emulator/emulator-unicorn.hpp"

namespace Emulator
{

    Unicorn::Unicorn()
    {
    }

    Unicorn::Unicorn(uc_arch arch, uc_mode mode) : m_err(uc_open(arch, mode, &m_uc))
    {
        if(m_err != UC_ERR_OK)
        {
            const std::string error = fmt::format("[{0}] Error in initialize emulator {0}:{0}", __FUNCTION__, m_err, uc_strerror(m_err));
            throw std::runtime_error(error);
        }
    }

    Unicorn::~Unicorn()
    {
        uc_close(m_uc);
    }

    void Unicorn::memMap(size_t size, uint32_t perms, uint64_t address)
    {
        m_err = uc_mem_map(m_uc, address, size, perms);
        if(m_err != UC_ERR_OK)
        {
            const std::string error = fmt::format("[{0}] Error in map memory emulator {0}:{0}", __FUNCTION__, m_err, uc_strerror(m_err));
            throw std::runtime_error(error);
        }
    }

    void Unicorn::memWrite(const void *_bytes, size_t size, 
                                    uint64_t address)
    {
        m_err = uc_mem_write(m_uc, address, _bytes, size);
        if(m_err != UC_ERR_OK)
        {
            const std::string error = fmt::format("[{0}] Error in map write memory emulator {0}:{0}", __FUNCTION__, m_err, uc_strerror(m_err));
            throw std::runtime_error(error);
        }
    }

    void Unicorn::regWrite(int regid, const void *value)
    {
        m_err = uc_reg_write(m_uc, regid, value);

        if(m_err != UC_ERR_OK)
        {
            const std::string error = fmt::format("[{0}] Error in write register {0} = {0}, {0}:{0}", __FUNCTION__, regid, value, m_err, uc_strerror(m_err));
            throw std::runtime_error(error);
        }
    }

    void Unicorn::startEmulator(uint64_t begin, uint64_t until,
                    uint64_t timeout, size_t count)
                    {
                        m_err = uc_emu_start(m_uc, begin, until, timeout, count);

                        if(m_err != UC_ERR_OK)
                        {
                            const std::string error = fmt::format("[{0}] Error in start emulator {0}:{0}", __FUNCTION__,  m_err, uc_strerror(m_err));
                            throw std::runtime_error(error);
                        }
                    }

    void* Unicorn::regRead(int regid)
    {
        void* value = nullptr;
        m_err = uc_reg_read(m_uc, regid, &value);

        if(m_err != UC_ERR_OK && value == nullptr)
        {
            const std::string error = fmt::format("[{0}] Error in start emulator {0}:{0}", __FUNCTION__,  m_err, uc_strerror(m_err));
            throw std::runtime_error(error);
        }

        return value;
    }
}