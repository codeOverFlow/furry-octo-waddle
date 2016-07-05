#include "../include/cpu.hpp"

Cpu::Cpu() : m_pc(ENTRY_POINT), m_i(0), m_stack(), m_systemDelay(0), m_soundDelay(0) {
   memset(m_memory, 0, MEMORY_SIZE);
   memset(m_v, 0, NB_REGISTER);

   m_mask[0] = 0x0000;  m_id[0]=0x0FFF;          /* 0NNN */
   m_mask[1] = 0xFFFF;  m_id[1]=0x00E0;          /* 00E0 */
   m_mask[2] = 0xFFFF;  m_id[2]=0x00EE;          /* 00EE */
   m_mask[3] = 0xF000;  m_id[3]=0x1000;          /* 1NNN */
   m_mask[4] = 0xF000;  m_id[4]=0x2000;          /* 2NNN */
   m_mask[5] = 0xF000;  m_id[5]=0x3000;          /* 3XNN */
   m_mask[6] = 0xF000;  m_id[6]=0x4000;          /* 4XNN */
   m_mask[7] = 0xF00F;  m_id[7]=0x5000;          /* 5XY0 */
   m_mask[8] = 0xF000;  m_id[8]=0x6000;          /* 6XNN */
   m_mask[9] = 0xF000;  m_id[9]=0x7000;          /* 7XNN */
   m_mask[10]= 0xF00F;  m_id[10]=0x8000;          /* 8XY0 */
   m_mask[11]= 0xF00F;  m_id[11]=0x8001;          /* 8XY1 */
   m_mask[12]= 0xF00F;  m_id[12]=0x8002;          /* 8XY2 */
   m_mask[13]= 0xF00F;  m_id[13]=0x8003;          /* BXY3 */
   m_mask[14]= 0xF00F;  m_id[14]=0x8004;          /* 8XY4 */
   m_mask[15]= 0xF00F;  m_id[15]=0x8005;          /* 8XY5 */
   m_mask[16]= 0xF00F;  m_id[16]=0x8006;          /* 8XY6 */
   m_mask[17]= 0xF00F;  m_id[17]=0x8007;          /* 8XY7 */
   m_mask[18]= 0xF00F;  m_id[18]=0x800E;          /* 8XYE */
   m_mask[19]= 0xF00F;  m_id[19]=0x9000;          /* 9XY0 */
   m_mask[20]= 0xF000;  m_id[20]=0xA000;          /* ANNN */
   m_mask[21]= 0xF000;  m_id[21]=0xB000;          /* BNNN */
   m_mask[22]= 0xF000;  m_id[22]=0xC000;          /* CXNN */
   m_mask[23]= 0xF000;  m_id[23]=0xD000;          /* DXYN */
   m_mask[24]= 0xF0FF;  m_id[24]=0xE09E;          /* EX9E */
   m_mask[25]= 0xF0FF;  m_id[25]=0xE0A1;          /* EXA1 */
   m_mask[26]= 0xF0FF;  m_id[26]=0xF007;          /* FX07 */
   m_mask[27]= 0xF0FF;  m_id[27]=0xF00A;          /* FX0A */
   m_mask[28]= 0xF0FF;  m_id[28]=0xF015;          /* FX15 */
   m_mask[29]= 0xF0FF;  m_id[29]=0xF018;          /* FX18 */
   m_mask[30]= 0xF0FF;  m_id[30]=0xF01E;          /* FX1E */
   m_mask[31]= 0xF0FF;  m_id[31]=0xF029;          /* FX29 */
   m_mask[32]= 0xF0FF;  m_id[32]=0xF033;          /* FX33 */
   m_mask[33]= 0xF0FF;  m_id[33]=0xF055;          /* FX55 */
   m_mask[34]= 0xF0FF;  m_id[34]=0xF065;          /* FX65 */
}

Cpu::~Cpu() {}

uint Cpu::memoryValue(uint index) {
   return m_memory[index];
}

void Cpu::setMemoryValue(uint index, uint value) {
   m_memory[index] = value;
}

uint Cpu::pcValue() {
   return m_pc;
}

void Cpu::setPcValue(uint addr) {
   m_pc = addr;
}

void Cpu::incrementPcBy(uint incr) {
   m_pc += incr;
}

uint Cpu::registerValue(uint index) {
   return m_v[index];
}

void Cpu::setRegisterValue(uint index, uint value) {
   m_v[index] = value;
}

uint Cpu::iValue() {
   return m_i;
}

void Cpu::setIValue(uint value) {
   m_i = value;
}

void Cpu::push(uint addr) {
   m_stack.push(addr);
}

uint Cpu::pop() {
   uint addr = m_stack.top();
   m_stack.pop();
   return addr;
}

uint Cpu::systemDelayValue() {
   return m_systemDelay;
}

void Cpu::setSystemDelayValue(uint value) {
   m_systemDelay = value;
}

uint Cpu::soundDelayValue() {
   return m_soundDelay;
}

void Cpu::setSoundDelayValue(uint value) {
   m_soundDelay = value;
}

void Cpu::tick() {
   if (m_systemDelay > 0)
      m_systemDelay--;
   if (m_soundDelay > 0)
      m_soundDelay--;
}

uint Cpu::maskValue(uint index) {
   return m_mask[index];
}

uint Cpu::idValue(uint index) {
   return m_id[index];
}

uint Cpu::opcode() {
   return (m_memory[m_pc] << 8) + m_memory[m_pc+1];
}

uint Cpu::action(uint opcode) {
   for (uint i = 0; i < NB_OPCODE; i++) {
      if ((m_mask[i] & opcode) == m_id[i])
         return i;
   }
   return 0;
}
