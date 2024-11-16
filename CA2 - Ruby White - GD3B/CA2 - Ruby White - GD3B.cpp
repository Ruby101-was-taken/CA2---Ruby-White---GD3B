// CA2 - Ruby White - GD3B.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TreeMapNode.h"
#include "BinaryTree.h"
#include "TreeMap.h"

int main()
{
	TreeMap<std::string, int> test;
	test.put("funny", 3);
	test.put("rub", 3);
	test.put("abc", 3);
	std::cout << test.contains("funny") << std::endl;
	std::cout << test.contains("rub") << std::endl;
	std::cout << test.contains("abc") << std::endl;
	std::cout << test.contains("sad") << std::endl;
}