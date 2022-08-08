#include <iostream>

int returnCode(int msg, int exitCode) {
	switch (msg) {
	case 0: std::cout << "Not enough arguments were provided.\nUse '--help' to see valid arguments" << std::endl; break;
	case 1: std::cout << "No patch directory was specified" << std::endl; break;
	case 2: std::cout << "The specified directory doesn't exist" << std::endl; break;
	case 3: std::cout << "A patch order file was not found" << std::endl; break;
	case 4: std::cout << ": Couldn't find patch" << std::endl;
	case 256: break;
	}

	if (exitCode == 512)
		return 0;
	else
		exit(exitCode);
}
