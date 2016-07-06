#include "../include/screen.hpp"

Screen::Screen() : m_window(sf::VideoMode(W, H), "Chip8 Emulator Test") {
   m_window.setPosition(sf::Vector2i(200, 200));
   for (uint y = 0; y < H_UNITS; y++) {
      for (uint x = 0; x < W_UNITS; x++) {
          sf::RectangleShape rect(sf::Vector2f(PIXEL_SIZE, PIXEL_SIZE));
          rect.setFillColor(sf::Color::Black);
          rect.setPosition(x*PIXEL_SIZE, y*PIXEL_SIZE);
          m_screen[y][x] = rect;
      }
   }
}

Screen::~Screen() {}

sf::RenderWindow* Screen::window() {
   return &m_window;
}

sf::RectangleShape Screen::screenValueAt(uint x, uint y) {
   return m_screen[y][x];
}

void Screen::setScreenValueAt(uint x, uint y, sf::RectangleShape value) {
   m_screen[y][x] = value;
}

void Screen::clear() {
   for (uint y = 0; y < H_UNITS; y++) {
      for (uint x = 0; x < W_UNITS; x++) {
          sf::RectangleShape rect(sf::Vector2f(PIXEL_SIZE, PIXEL_SIZE));
          rect.setFillColor(sf::Color::Black);
          rect.setPosition(x*PIXEL_SIZE, y*PIXEL_SIZE);
          m_screen[y][x] = rect;
      }
   }
}

void Screen::print() {
   for (uint y = 0; y < H_UNITS; y++) {
      for(uint x = 0; x < W_UNITS; x++) {
         m_window.draw(m_screen[y][x]);
      }
   }  
}
