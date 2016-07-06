#pragma once

#include "constants.hpp"

#include <stack>
#include <string.h>

class Cpu {
   private:
      uint m_memory[MEMORY_SIZE];
      uint m_pc;
      uint m_v[NB_REGISTER];
      uint m_i;
      std::stack<uint> m_stack;
      uint m_systemDelay;
      uint m_soundDelay;
      uint m_mask[NB_OPCODE];
      uint m_id[NB_OPCODE];
   public:
      Cpu();
      ~Cpu();
      uint* memory();
      uint memoryValue(uint index);
      void setMemoryValue(uint index, uint value);
      uint pcValue();
      void setPcValue(uint addr);
      void incrementPcBy(uint incr);
      uint registerValue(uint index);
      void setRegisterValue(uint index, uint value);
      uint iValue();
      void setIValue(uint value);
      void push(uint addr);
      uint pop();
      uint systemDelayValue();
      void setSystemDelayValue(uint value);
      uint soundDelayValue();
      void setSoundDelayValue(uint value);
      void tick();
      uint maskValue(uint index);
      uint idValue(uint index);
      uint opcode();
      uint action(uint opcode);
};
