#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../CA2 - Ruby White - GD3B/BSTNode.h"
#include "../CA2 - Ruby White - GD3B/TreeMapNode.h"
#include "../CA2 - Ruby White - GD3B/BinaryTree.h"
#include "../CA2 - Ruby White - GD3B/TreeMap.h"

void ExecuteSplit(const std::string fileName, const bool careForCases = false, const bool includeNonAplhaNumericCharacters = false);


void addWordToTree(const char& keyChar, std::string& word, TreeMap<char, BinaryTree<std::string>>& wordsTree, const bool careForCases = false) {
	if(!careForCases) {
		word[0] = std::toupper(word[0]);
	}
	wordsTree.get(keyChar).add(word);
}

void attemptWordAdd(std::string& word, TreeMap<char, BinaryTree<std::string>>& wordsTree, const bool careForCases, const bool includeNonAlphaNumericChatacter) {
	char keyChar = word[0];
	bool canAddWord = true;
	if(!includeNonAlphaNumericChatacter) {
		if((keyChar <= 47) || (keyChar >= 58 && keyChar <= 64) || (keyChar >= 91 && keyChar <= 96) || (keyChar >=123))
			return;
	}
	// continue if the character is valid or we do not care for char type
	if(!careForCases)
		keyChar = std::toupper(keyChar);
	if(!wordsTree.contains(keyChar)) {
		wordsTree.put(keyChar, BinaryTree<std::string>());
		addWordToTree(keyChar, word, wordsTree, careForCases);
	}
	else if(!wordsTree.get(keyChar).contains(word))
		addWordToTree(keyChar, word, wordsTree, careForCases);
}

TreeMap<char, BinaryTree<std::string>> SplitFile(const std::string& fileName, const bool careForCases = true, const bool includeNonAlphaNumericChatacter = false) {
	TreeMap<char, BinaryTree<std::string>> wordsTree;
	ifstream in(fileName);
	if(in) {
		std::string line = "";
		while(std::getline(in, line, ' ')) {
			std::stringstream nonewLine(line); // https://stackoverflow.com/questions/10058606/splitting-a-string-by-a-character 24/11/2024
			std::string word = "";
			while(std::getline(nonewLine, word, '\n')) {
				attemptWordAdd(word, wordsTree, careForCases, includeNonAlphaNumericChatacter);
			}
		}
		in.close();
	}
	else {
		throw("Could not find file \"" + fileName + "\" :(");
	}
	return wordsTree;
}


void SplitLoop(TreeMap<char, BinaryTree<std::string>>& treeMap) {
	bool run = treeMap.size() > 0;

	if(!run) {
		std::cout << "File Empty." << std::endl;
		return;
	}

	treeMap.print();

	while(run) {
		std::cout << "1: Search for Char.(Shows the list for a particular char key)\n2: Count of Words for Char Key.(Shows the count for a particular char key)\n0: Load new file.\n> ";
		int ans = 0;
		std::cin >> ans;
		switch(ans) {
		case 1: {
			std::string userInput;
			std::cout << "Enter the char you want to view.(Case Sensative)\n> ";
			std::cin >> userInput;
			std::cout << "\n{" << treeMap[userInput[0]] << "}\n" << std::endl;
			break;
		}
		case 2: {
			std::string userInput;
			std::cout << "Enter the char you want to view.(Case Sensative)\n> ";
			std::cin >> userInput;
			std::cout << "\nThere are " << treeMap[userInput[0]].count() << " Words for the Char Key '" << userInput[0] << "'\n" << std::endl;
			break;
		}
		case 0:
			run = false;
			break;
		default:
			break;
		}
	}
}

std::string getFileName() {
	std::string fileName = "";
	std::cout << "Enter File Name (include file extension):\n> ";
	std::cin >> fileName;
	return fileName;
}

void StartSplit() {
	std::string fileName = getFileName();

	ExecuteSplit(fileName);
}
void StartSplitAdvanced() {
	std::string fileName = getFileName();

	int ans;
	std::cout << "Seprate Characters of different cases. (1: yes, 0: no)\n> ";
	std::cin >> ans;
	bool careForCases = (ans == 0) ? false : true;

	std::cout << "Include non numeric/aplhabetic characters. (1: yes, 0: no)\n> ";
	std::cin >> ans;
	bool includeNonAplhaNumericCharacters = (ans == 0) ? false : true;

	ExecuteSplit(fileName, careForCases, includeNonAplhaNumericCharacters);
}

void ExecuteSplit(const std::string fileName, const bool careForCases, const bool includeNonAplhaNumericCharacters){
	TreeMap<char, BinaryTree<std::string>> split = SplitFile(fileName, careForCases, includeNonAplhaNumericCharacters);
	SplitLoop(split);
}

void SplitMain() {

	bool run = true;
	while(run) {
		std::cout << "1: Load File. (Loads a file and shows the output)\n2: Load File Advanced. (Loads a file with more settings)\n0: Quit. (Returns to the Main Menu)\n> ";
		int ans = 0;
		std::cin >> ans;
		switch(ans) {
			case 1:
				StartSplit();
				break;
			case 2:
				StartSplitAdvanced();
				break;
			case 0:
				run = false;
				break;
		default:
			break;
		}
	}
}