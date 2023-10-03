#pragma once

#include <unicorn/unicorn.h>

// memory address where emulation starts default
#define ADDRESS_START_EMULATION 0x1000000

namespace Emulator
{
    class Unicorn
    {
    private:
        uc_engine *m_uc;
        uc_err m_err;

    public:
        Unicorn();
        Unicorn(uc_arch arch, uc_mode mode);
        ~Unicorn();

        void memMap(size_t size, uint32_t perms,
                    uint64_t address = ADDRESS_START_EMULATION);
        void memWrite(const void *_bytes, size_t size,
                      uint64_t address = ADDRESS_START_EMULATION);

        void regWrite(int regid, const void *value);

        void *regRead(int regid);

        void startEmulator(uint64_t begin, uint64_t until,
                           uint64_t timeout, size_t count);
    };
}