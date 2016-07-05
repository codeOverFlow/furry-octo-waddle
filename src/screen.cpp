#include "../include/screen.hpp"

Screen::Screen() {
   for (uint y = 0; y < H_UNITS; y++)
      memset(m_screen[y], '.', W_UNITS);
}

Screen::~Screen() {}

char Screen::screenValueAt(uint x, uint y) {
   return m_screen[y][x];
}

void Screen::setScreenValueAt(uint x, uint y, char value) {
   m_screen[y][x] = value;
}

void Screen::clear() {
   for (uint y = 0; y < H_UNITS; y++)
      memset(m_screen[y], '.', W_UNITS); 
}

void Screen::print() {
   for (uint y = 0; y < H_UNITS; y++) {
      for(uint x = 0; x < W_UNITS; x++) {
         std::cout << m_screen[y][x];
      }
      std::cout << std::endl;
   }  
}
