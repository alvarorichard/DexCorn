#include <iostream>
#include "emulator/emulator-unicorn.hpp"
#include "parser/dalvik/parser-dalvik.hpp"
#include "covinhas/emulator-dalvik.hpp"

// code to be emulated
#define X86_CODE32 "\x41\x4a" // INC ecx; DEC edx


int main(int argc, char **argv, char **envp)
{
  Emulator::Unicorn emulator(UC_ARCH_X86, UC_MODE_32);

  int r_ecx = 0x1234;     // ECX register
  int r_edx = 0x7891;     // EDX register

  printf("Emulate i386 code\n");

  // Initialize emulator in X86-32bit mode

  // map 2MB memory for this emulation
  emulator.memMap(2 * 1024 * 1024, UC_PROT_ALL);

  // write machine code to be emulated to memory
  emulator.memWrite(X86_CODE32, sizeof(X86_CODE32) - 1);

  // initialize machine registers
  emulator.regWrite(UC_X86_REG_ECX, &r_ecx);
  emulator.regWrite(UC_X86_REG_EDX, &r_edx);

  // emulate code in infinite time & unlimited instructions
  emulator.startEmulator(ADDRESS_START_EMULATION, ADDRESS_START_EMULATION + sizeof(X86_CODE32) - 1, 0, 0);

  // now print out some registers
  printf("Emulation done. Below is the CPU context\n");

  void* ecx = emulator.regRead(UC_X86_REG_ECX);
  void* edx = emulator.regRead(UC_X86_REG_EDX);
  
  printf(">>> ECX = 0x%x\n", ecx);
  printf(">>> EDX = 0x%x\n", edx);


  std::string test = "/home/mob/Documentos/Bounty/C6Bank/c6_dex/classes4.dex";
  Covinhas::Dalvik covinhas(test);

  Parser::Dalvik parser(test);

  //parser.getAllMethods();

  std::cout << std::endl << covinhas.setMethodToEmulator("onImageAvailable", "a").underlying_array_type << std::endl;
  


  return 0;
}