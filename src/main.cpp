#include <cstdlib>

#include "../include/system.hpp"

int main (void) {
   System system;
   system.loadRom("../games/TICTAC");
   system.runtime();
	return EXIT_SUCCESS;
}
