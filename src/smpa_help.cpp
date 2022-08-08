#include <iostream>

#include "config.hpp"
#include "return_codes.hpp"
#include "colors.hpp"

void showHelp(void) {
	int i;
	std::cout << "Simple Multi-Patch Applier " << BOLD << FG_MAGENTA << "v" << VERSION_NUM << RESET << std::endl;
	std::cout << "----------------------------";
	
	for (i = 0; i != sizeof(VERSION_NUM) - 1; i++)
		std::cout << "-";

	std::cout <<
"\n\
SMPA is a program to apply multiple patches at once via the use of\n\
a 'patch_order' file (see docs/patch_order).\n\
\n\
  " << BOLD << FG_LIGHT_GREEN << "--help       -h" << RESET << "     Show this help\n\
  " << BOLD << FG_LIGHT_GREEN << "--license    -L" << RESET << "     Show the GPL3 License\n\
  " << BOLD << FG_LIGHT_GREEN << "--directory  -d" << RESET << "     Use a directory of patches\n\
  " << BOLD << FG_LIGHT_GREEN << "--edit       -e" << RESET << "     Edit the 'patch_order' file\n\
\n\
SMPA is licensed under the " << LICENSE << "\n\
Source code is free at " << BOLD << FG_LIGHT_CYAN << GIT_URL << RESET << std::endl;

	returnCode(256, 0);
	return;
}
