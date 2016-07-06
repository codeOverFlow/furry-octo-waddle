#pragma once

#include "constants.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>

#include <string.h>


class Screen {
   private:
      sf::RectangleShape m_screen[H_UNITS][W_UNITS];
      sf::RenderWindow m_window;
   public:
      Screen();
      ~Screen();
      sf::RenderWindow* window();
      sf::RectangleShape screenValueAt(uint x, uint y);
      void setScreenValueAt(uint x, uint y, sf::RectangleShape value);
      void clear();
      void print();
};
