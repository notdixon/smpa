#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

#include "config.hpp"
#include "return_codes.hpp"
#include "smpa_help.hpp"
#include "prepatch.hpp"
#include "license.hpp"

int main(int argc, char* argv[]) {
	if (argc < 2)
		returnCode(0, -1);
	
	std::string patchDir;
	std::string lookAhead;

	bool wantEdit = false;

	for (int i = 1; i < argc; i++) {
		std::string arg = argv[i];

		if (arg.compare("--help") == 0 || arg.compare("-h") == 0)
			showHelp();

		if (arg.compare("--license") == 0 || arg.compare("-L") == 0)
			showGPL();
	
		if (arg.compare("--edit") == 0 || arg.compare("-e") == 0)
			wantEdit = true;

		if (arg.compare("--directory") == 0 || arg.compare("-d") == 0) {
			if (argv[i + 1] == NULL)
				returnCode(1, -1);
			else {
				patchDir = argv[i + 1];
				
				if
					(argv[i + 2] != NULL) {
					lookAhead = argv[i + 2];
					
					if (lookAhead.compare("--edit") == 0 ||
						lookAhead.compare("-e") == 0)
						wantEdit = true;
				}

				if (wantEdit == true)
					editPatchOrder(patchDir);
				else {
					checkPatchDirectory(patchDir);
				}
			}
			return 0;
		}

	}

	return 0;
}
