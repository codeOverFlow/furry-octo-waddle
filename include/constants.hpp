#pragma once

typedef unsigned int uint;

// CPU
const uint MEMORY_SIZE = 4096;
const uint ENTRY_POINT = 0x200;
const uint NB_OPCODE = 35;
const uint NB_REGISTER = 16;

// SCREEN
const uint W_UNITS = 64;
const uint H_UNITS = 32;

// FOR SFML
const uint PIXEL_SIZE = 8;
const uint W = W_UNITS * PIXEL_SIZE;
const uint H = H_UNITS * PIXEL_SIZE;

// SYSTEM
const uint SLEEP_TIME = 16.67;
const uint CYCLE = 4;
