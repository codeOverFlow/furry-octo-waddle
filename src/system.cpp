#include "../include/system.hpp"

System::System() : m_cpu(), m_screen(), m_generator(), m_dist(0,255) {
   m_cpu.setMemoryValue(m_cpu.pcValue(), 0x61);
   m_cpu.setMemoryValue(m_cpu.pcValue() + 1, 0x02);
   m_cpu.setMemoryValue(m_cpu.pcValue() + 2, 0xF1);
   m_cpu.setMemoryValue(m_cpu.pcValue() + 3, 0x29);
   m_cpu.setMemoryValue(m_cpu.pcValue() + 4, 0xD0);
   m_cpu.setMemoryValue(m_cpu.pcValue() + 5, 0x05);
   m_cpu.setMemoryValue(m_cpu.pcValue() + 6, 0x61);
   m_cpu.setMemoryValue(m_cpu.pcValue() + 7, 0x0f);
   m_cpu.setMemoryValue(m_cpu.pcValue() + 8, 0xF1);
   m_cpu.setMemoryValue(m_cpu.pcValue() + 9, 0x29);
   m_cpu.setMemoryValue(m_cpu.pcValue() + 10, 0xD5);
   m_cpu.setMemoryValue(m_cpu.pcValue() + 11, 0x05);
   // FONT
   m_cpu.setMemoryValue(0, 0xF0);  m_cpu.setMemoryValue(1, 0x90);  m_cpu.setMemoryValue(2, 0x90);  m_cpu.setMemoryValue(3, 0x90);  m_cpu.setMemoryValue(4, 0xF0);  // O 
   m_cpu.setMemoryValue(5, 0x20);  m_cpu.setMemoryValue(6, 0x60);  m_cpu.setMemoryValue(7, 0x20);  m_cpu.setMemoryValue(8, 0x20);  m_cpu.setMemoryValue(9, 0x70);  // 1 
   m_cpu.setMemoryValue(10, 0xF0); m_cpu.setMemoryValue(11, 0x10); m_cpu.setMemoryValue(12, 0xF0); m_cpu.setMemoryValue(13, 0x80); m_cpu.setMemoryValue(14, 0xF0); // 2 
   m_cpu.setMemoryValue(15, 0xF0); m_cpu.setMemoryValue(16, 0x10); m_cpu.setMemoryValue(17, 0xF0); m_cpu.setMemoryValue(18, 0x10); m_cpu.setMemoryValue(19, 0xF0); // 3 
   m_cpu.setMemoryValue(20, 0x90); m_cpu.setMemoryValue(21, 0x90); m_cpu.setMemoryValue(22, 0xF0); m_cpu.setMemoryValue(23, 0x10); m_cpu.setMemoryValue(24, 0x10); // 4 
   m_cpu.setMemoryValue(25, 0xF0); m_cpu.setMemoryValue(26, 0x80); m_cpu.setMemoryValue(27, 0xF0); m_cpu.setMemoryValue(28, 0x10); m_cpu.setMemoryValue(29, 0xF0); // 5 
   m_cpu.setMemoryValue(30, 0xF0); m_cpu.setMemoryValue(31, 0x80); m_cpu.setMemoryValue(32, 0xF0); m_cpu.setMemoryValue(33, 0x90); m_cpu.setMemoryValue(34, 0xF0); // 6 
   m_cpu.setMemoryValue(35, 0xF0); m_cpu.setMemoryValue(36, 0x10); m_cpu.setMemoryValue(37, 0x20); m_cpu.setMemoryValue(38, 0x40); m_cpu.setMemoryValue(39, 0x40); // 7 
   m_cpu.setMemoryValue(40, 0xF0); m_cpu.setMemoryValue(41, 0x90); m_cpu.setMemoryValue(42, 0xF0); m_cpu.setMemoryValue(43, 0x90); m_cpu.setMemoryValue(44, 0xF0); // 8 
   m_cpu.setMemoryValue(45, 0xF0); m_cpu.setMemoryValue(46, 0x90); m_cpu.setMemoryValue(47, 0xF0); m_cpu.setMemoryValue(48, 0x10); m_cpu.setMemoryValue(49, 0xF0); // 9 
   m_cpu.setMemoryValue(50, 0xF0); m_cpu.setMemoryValue(51, 0x90); m_cpu.setMemoryValue(52, 0xF0); m_cpu.setMemoryValue(53, 0x90); m_cpu.setMemoryValue(54, 0x90); // A 
   m_cpu.setMemoryValue(55, 0xE0); m_cpu.setMemoryValue(56, 0x90); m_cpu.setMemoryValue(57, 0xE0); m_cpu.setMemoryValue(58, 0x90); m_cpu.setMemoryValue(59, 0xE0); // B 
   m_cpu.setMemoryValue(60, 0xF0); m_cpu.setMemoryValue(61, 0x80); m_cpu.setMemoryValue(62, 0x80); m_cpu.setMemoryValue(63, 0x80); m_cpu.setMemoryValue(64, 0xF0); // C 
   m_cpu.setMemoryValue(65, 0xE0); m_cpu.setMemoryValue(66, 0x90); m_cpu.setMemoryValue(67, 0x90); m_cpu.setMemoryValue(68, 0x90); m_cpu.setMemoryValue(69, 0xE0); // D 
   m_cpu.setMemoryValue(70, 0xF0); m_cpu.setMemoryValue(71, 0x80); m_cpu.setMemoryValue(72, 0xF0); m_cpu.setMemoryValue(73, 0x80); m_cpu.setMemoryValue(74, 0xF0); // E 
   m_cpu.setMemoryValue(75, 0xF0); m_cpu.setMemoryValue(76, 0x80); m_cpu.setMemoryValue(77, 0xF0); m_cpu.setMemoryValue(78, 0x80); m_cpu.setMemoryValue(79, 0x80); // F
}

System::~System() {}

void System::interpretOpcode() {
   uint opcode = m_cpu.opcode();
   printf("HERE: %04x\n", opcode);
   uint b3 = (opcode & 0x0F00) >> 8;
   uint b2 = (opcode & 0x00F0) >> 4;
   uint b1 = opcode & 0x000F;

   uint nn = (b2 << 4) + b1;
   uint nnn = (b3 << 8) + nn;

   switch (m_cpu.action(opcode)) {
      case 0:
         // deprecated
         break;
      case 1:
         m_screen.clear();
         break;
      case 2:
         m_cpu.setPcValue(m_cpu.pop()-2);
         break;
      case 3:
         m_cpu.setPcValue(nnn-2);
         break;
      case 4:
         m_cpu.push(m_cpu.pcValue());
         m_cpu.setPcValue(nnn-2);
         break;
      case 5:
         if (m_cpu.registerValue(b3) == nn)
            m_cpu.incrementPcBy(2);
         break;
      case 6:
         if (m_cpu.registerValue(b3) != nn)
            m_cpu.incrementPcBy(2);
         break;
      case 7:
         if (m_cpu.registerValue(b3) == m_cpu.registerValue(b2))
            m_cpu.incrementPcBy(2);
         break;
      case 8:
         std::cout << "load " << nn << " in Vx" << std::endl;
         m_cpu.setRegisterValue(b3, nn);
         break;
      case 9:
         m_cpu.setRegisterValue(b3, m_cpu.registerValue(b3) + nn);
         break;
      case 10:
         m_cpu.setRegisterValue(b3, m_cpu.registerValue(b2));
         break;
      case 11:
         m_cpu.setRegisterValue(b3, m_cpu.registerValue(b3) | m_cpu.registerValue(b2));
         break;
      case 12:
         m_cpu.setRegisterValue(b3, m_cpu.registerValue(b3) & m_cpu.registerValue(b2));
         break;
      case 13:
         m_cpu.setRegisterValue(b3, m_cpu.registerValue(b3) ^ m_cpu.registerValue(b2));
         break;
      case 14:
         m_cpu.setRegisterValue(b3, m_cpu.registerValue(b3) + m_cpu.registerValue(b2));
         if (m_cpu.registerValue(b3) > 0x00ff) {
            m_cpu.setRegisterValue(0xf, 1);
            m_cpu.setRegisterValue(b3, m_cpu.registerValue(b3) & 0x00ff);
         }
         else {
            m_cpu.setRegisterValue(0xf, 0);
         }
         break;
      case 15:
         if (m_cpu.registerValue(b3) > m_cpu.registerValue(b2))
            m_cpu.setRegisterValue(0xf, 1);
         else
            m_cpu.setRegisterValue(0xf, 0);
         m_cpu.setRegisterValue(b3, m_cpu.registerValue(b3) - m_cpu.registerValue(b2));
         break; 
      case 16:
         m_cpu.setRegisterValue(0xf, m_cpu.registerValue(b3) & 0x1);
         m_cpu.setRegisterValue(b3, m_cpu.registerValue(b3) >> 1);
         break;
      case 17:
         if (m_cpu.registerValue(b2) > m_cpu.registerValue(b3))
            m_cpu.setRegisterValue(0xf, 1);
         else
            m_cpu.setRegisterValue(0xf, 0);
         m_cpu.setRegisterValue(b3, m_cpu.registerValue(b2) - m_cpu.registerValue(b3));
         break;
      case 18:
         m_cpu.setRegisterValue(0xf, m_cpu.registerValue(b3) & 0x80);
         m_cpu.setRegisterValue(b3, m_cpu.registerValue(b3) << 1);
         break;
      case 19:
         if (m_cpu.registerValue(b3) != m_cpu.registerValue(b2))
            m_cpu.incrementPcBy(2);
         break;
      case 20:
         m_cpu.setIValue(nnn);
         break;
      case 21:
         m_cpu.setPcValue(nnn + m_cpu.registerValue(0) - 2);
         break;
      case 22:
         m_cpu.setRegisterValue(b3, m_dist(m_generator) & nn);
         break;
      case 23:
         std::cout << "Draw" << std::endl;
         draw(b3, b2, b1);
         break;
      case 24:
         // skip if Vx is pressed
         break;
      case 25:
         // skip if Vx is no pressed
         break;
      case 26:
         m_cpu.setRegisterValue(b3, m_cpu.systemDelayValue());
         break;
      case 27:
         // block and wait for key
         break;
      case 28:
         m_cpu.setSystemDelayValue(m_cpu.registerValue(b3));
         break;
      case 29:
         m_cpu.setSoundDelayValue(m_cpu.registerValue(b3));
         break;
      case 30:
         m_cpu.setIValue(m_cpu.iValue() + m_cpu.registerValue(b3));
         break;
      case 31:
         m_cpu.setIValue(5*m_cpu.registerValue(b3));
         std::cout << "I = " << m_cpu.iValue() << std::endl;
         break;
      case 32: 
         {
            uint tmp = m_cpu.registerValue(b3);
            m_cpu.setMemoryValue(m_cpu.iValue(), (tmp - (tmp % 100))/100);
            m_cpu.setMemoryValue(m_cpu.iValue()+1, ((tmp - (tmp % 10))/10)%10);
            m_cpu.setMemoryValue(m_cpu.iValue()+2, m_cpu.registerValue(b3) - m_cpu.memoryValue(m_cpu.iValue()) * 100 - m_cpu.memoryValue(m_cpu.iValue()+1) * 10);
            break;
         }
      case 33:
         for (uint i = 0; i < NB_REGISTER; i++)
            m_cpu.setMemoryValue(m_cpu.iValue() + i, m_cpu.registerValue(i));
         break;
      case 34:
         for (uint i = 0; i < NB_REGISTER; i++)
            m_cpu.setRegisterValue(i, m_cpu.memoryValue(m_cpu.iValue() + i));
         break;
      default:
         // bad opcode
         break;
   }
   m_cpu.incrementPcBy(2);
}

void System::runtime() {
   while(true) {
      for (uint i = 0; i < CYCLE; i++)
         interpretOpcode();
      m_screen.print();
      m_cpu.tick();
   }
}

void System::draw(uint x, uint y, uint heigth) {
   uint xx = 0;
   uint yy = 0;
   uint k = 0;
   uint codage = 0;
   uint j = 0;
   uint offset = 0;
   m_cpu.setRegisterValue(0xf, 0);

   for (k = 0; k < heigth; k++) {
      codage = m_cpu.memoryValue(m_cpu.iValue() + k);
      std::cout << codage << std::endl;
      yy = (y+k)%H_UNITS;
      offset = 7;
      for (j = 0; j < 8; j++) {
         xx = (x+j) % W_UNITS;
         uint res = codage & (0x1 << offset);
         if (res != 0) {
            if (m_screen.screenValueAt(xx, yy) == '#') {
               m_screen.setScreenValueAt(xx, yy, '.');
               m_cpu.setRegisterValue(0xf, 1);
            }
            else {
               m_screen.setScreenValueAt(xx, yy, '#');
            }
         }
         if (offset > 0)
            offset--;
      }
   }
}
