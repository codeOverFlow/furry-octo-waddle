#pragma once

#include "cpu.hpp"
#include "screen.hpp"

#include <random>

class System {
   private:
      Cpu m_cpu;
      Screen m_screen;
      std::default_random_engine m_generator;
      std::uniform_int_distribution<uint> m_dist;
   public:
      System();
      ~System();
      void interpretOpcode();
      void runtime();
      void draw(uint x, uint y, uint heigth);
};
