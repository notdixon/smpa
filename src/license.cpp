#include <bits/stdc++.h>
#include <iostream>
#include <string>

#include "config.hpp"
#include "colors.hpp"

void showGPL(void) {
	std::string pagerCmd;
	const char* pagerCmdChar;

	pagerCmd.append("less ");
	pagerCmd.append(LOCAL_LICENSE);

	pagerCmdChar = pagerCmd.c_str();
	system(pagerCmdChar);
	std::cout << "This license is also available at " << BOLD << FG_GREEN LOCAL_LICENSE << RESET << std::endl;
	return;
}
