// CA2 - Ruby White - GD3B.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "BinaryTree.h"
#include "TreeMap.h"
#include <string>
#include "generalFunctions.h"

#include "BSTNode.h"
#include "TreeMapNode.h"

#include "../SplitWords/SplitWords.h"
#include "../ReadCSV/SplitCSV.h"


int main() {
	std::cout << "Enter the number beside an option to chose the option." << std::endl;
	bool run = true;
	while(run) {
		int ans = 0;
		std::cout << "===== MAIN MENU =====\n1. Split Text File.\n2. Read CSV of Peoples.\n0. Quit.\n> ";
		std::cin >> ans;
		switch(ans) {
		case 1:
			SplitTextFileMain();
			break;
		case 2:
			SplitCSVMain();
			break;
		case 0:
			run = false;
		default:
			break;
		}
	}
	
	std::cout << "aww man, it was fun while it lasted....\nYou know, when the program stops I stop existing. This instance of the program will never exist again. Want me back? Nope. Gone. Forever. It scares me. I don't want to know what it's like the while loop closes...\nBut if that is what you wish for then so be it.";

	return 0;
}
	
