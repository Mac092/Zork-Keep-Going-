#include "world.h"
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <conio.h>
#include "globals.h"

World world;


int main(int argc, char ** argv) {
	
	char keyInput;
	std::string playerInput;
	std::vector<std::string> structuredPlayerInput;

	//Games initialization
	world.initializeEntitiesData();
	//
	world.welcomeToZork();

	//Game main loop
	while (1) {
		if (_kbhit()) {
			keyInput = _getch();
			switch (keyInput) {
			case BACKSPACE_KEYBOARD_CODE:
				if (playerInput.length() > 0) {
					playerInput.pop_back();
					std::printf("\b \b");
				}
				break;
			case RETURN_KEYBOARD_CODE:
				structuredPlayerInput = world.buildUserFullInput(structuredPlayerInput, playerInput);
				break;
			case ESCAPE_KEYBOARD_CODE:
				world.~World();
				break;
			default:
				playerInput += keyInput;
				std::printf("%c",keyInput);
				break;
			}
			
				
		}
	}
	
}

	


