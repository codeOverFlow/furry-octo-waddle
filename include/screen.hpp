#pragma once

#include "constants.hpp"

#include <iostream>

#include <string.h>

class Screen {
   private:
      char m_screen[H_UNITS][W_UNITS];
   public:
      Screen();
      ~Screen();
      char screenValueAt(uint x, uint y);
      void setScreenValueAt(uint x, uint y, char value);
      void clear();
      void print();
};
