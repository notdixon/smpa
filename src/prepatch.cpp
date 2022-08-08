#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <cstring>
#include <bits/stdc++.h>

#include "return_codes.hpp"
#include "patcher.hpp"

int checkPatchDirectory(std::string patchDirectory) {
	const std::filesystem::path &path = patchDirectory;
	std::string patchOrderFileName;

	patchOrderFileName.append(patchDirectory);
	patchOrderFileName.append("/patch_order");
	
	/*
	 * Let's see if the directory doesn't exist. Why checking for it
	 * to not exist? Well if it doesn't, we hand off to 'returnCode'
	 * and that exits.
	 */
	if (!std::filesystem::exists(path))
		returnCode(2, -1);

	std::ifstream patchOrder;
	patchOrder.open(patchOrderFileName);

	if (!patchOrder)
		returnCode(3, -1);

	patchOrder.close();
	doPatches(patchOrderFileName, patchDirectory);
	return 0;
}

int editPatchOrder(std::string patchDirectory) {
	const std::filesystem::path &path = patchDirectory;
	std::string patchOrderFileName;
	const char* execCmd;

	patchOrderFileName.append("$EDITOR ");
	patchOrderFileName.append(patchDirectory);
	patchOrderFileName.append("/patch_order");

	execCmd = patchOrderFileName.c_str();
	system(execCmd);
	return 0;
}
