/*
 * This file applies patches from a directory
 */

#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

#include "colors.hpp"
#include "return_codes.hpp"

// Apply from Directory
int doPatches(std::string patchOrder, std::string patchDir) {
	std::ifstream patchOrderFile;
	patchOrderFile.open(patchOrder);

	const char* patchCmdChar;
	std::string patchCmdString;
	int i = 0;
	int appliedPatches = 0;
	bool foundFile = false;

	for (std::string line; getline(patchOrderFile, line);) {
		foundFile = false;
		patchCmdString = "";
		patchCmdString.append("patch -i ");

		// If the patch doesn't exist in this dir, try
		// the dir provided with
		if (!std::filesystem::exists(line)) {
			std::string newLine;
			newLine.append(patchDir);
			newLine.append("/");
			newLine.append(line);
			if (!std::filesystem::exists(newLine)) {
				std::cout << line;
				returnCode(4, 512);
			} else {
				patchCmdString.append(patchDir);
				patchCmdString.append("/");
				foundFile = true;
			}
		} else
			foundFile = true;
		patchCmdString.append(line);
		patchCmdChar = patchCmdString.c_str();
		if (foundFile == true) {
			system(patchCmdChar);
			appliedPatches++;
		}
		i++;
	}

	std::cout << "Applied " << BOLD << FG_GREEN << appliedPatches << RESET << " patch";
	if (appliedPatches == 1)
		std::cout << std::endl;
	else
		std::cout << "es" << std::endl;
	return 0;
}
