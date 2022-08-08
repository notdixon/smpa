/*
 * This file applies patches from a directory
 */

#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

#include "colors.hpp"

// Apply from Directory
int doPatches(std::string patchOrder, std::string patchDir) {
	std::ifstream patchOrderFile;
	patchOrderFile.open(patchOrder);

	const char* patchCmdChar;
	std::string patchCmdString;
	int i = 0;

	for (std::string line; getline(patchOrderFile, line);) {
		patchCmdString = "";
		patchCmdString.append("patch -i ");
		patchCmdString.append(patchDir);
		patchCmdString.append("/");
		patchCmdString.append(line);

		patchCmdChar = patchCmdString.c_str();
		system(patchCmdChar);
		i++;
	}

	std::cout << "Applied " << BOLD << FG_GREEN << i << RESET << " patches" << std::endl;
	return 0;
}
