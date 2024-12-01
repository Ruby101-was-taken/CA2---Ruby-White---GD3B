#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "Keys.h"
#include "Person.h"

#include "../CA2 - Ruby White - GD3B/TreeMap.h"

Person LoadPersonData(std::ifstream& in) {
	// get name
	std::string word = "";
	std::getline(in, word, ',');
	std::string name = word;

	// get times played sonic 2
	std::getline(in, word, ',');
	int timesPlayedSonic2 = std::stoi(word);

	// get fav num
	std::getline(in, word, ',');
	int favNum = std::stoi(word);

	// get hated num
	std::getline(in, word, ',');
	int hatedNum = std::stoi(word);

	// get contrartian status
	std::getline(in, word, ',');
	std::string contrarian = word;

	// get skill level
	std::getline(in, word, ',');
	char skill = word[0];
	Person person(name, timesPlayedSonic2, favNum, hatedNum, contrarian, skill);
	return person;
}

template <class T >
void addPersonIndexName(TreeMap<T, BinaryTree<Person>>& map, Person person) {
	if(!map.contains(person.name)) {
		BinaryTree<Person> temp;
		map.put(person.name, temp);
	}
	map[person.name].add(person);
}
template <class T >
void addPersonIndexSonic2(TreeMap<T, BinaryTree<Person>>& map, Person person) {
	if(!map.contains(person.timesPlayedSonic2)) {
		BinaryTree<Person> temp;
		map.put(person.timesPlayedSonic2, temp);
	}
	map[person.timesPlayedSonic2].add(person);
}
template <class T >
void addPersonIndexFavNumber(TreeMap<T, BinaryTree<Person>>& map, Person person) {
	if(!map.contains(person.favouriteNumber)) {
		BinaryTree<Person> temp;
		map.put(person.favouriteNumber, temp);
	}
	map[person.favouriteNumber].add(person);
}
template <class T >
void addPersonIndexHatedNumber(TreeMap<T, BinaryTree<Person>>& map, Person person) {
	if(!map.contains(person.hatedNumber)) {
		BinaryTree<Person> temp;
		map.put(person.hatedNumber, temp);
	}
	map[person.hatedNumber].add(person);
}
template <class T >
void addPersonIndexSkillLevel(TreeMap<T, BinaryTree<Person>>& map, Person person) {
	if(!map.contains(person.skillLevel)) {
		BinaryTree<Person> temp;
		map.put(person.skillLevel, temp);
	}
	map[person.skillLevel].add(person);
}

template <class T>
void ReadPersonData(TreeMap<T, BinaryTree<Person>>& people, const std::string& fileName, IndexKeys key = TIMES_PLAYED_SONIC2) {
	ifstream in(fileName);
	// skip headers...
	std::string next = "";
	std::getline(in, next, '\n');
	if(in) {
		next = "";
		while(!in.eof()) {
			Person person = LoadPersonData(in);
			std::getline(in, next, '\n'); // gets rid of any new line characters at the end
			switch(key) {
			case TIMES_PLAYED_SONIC2:
				addPersonIndexSonic2(people, person);
				break;
			case FAVOURITE_NUMBER:
				addPersonIndexFavNumber(people, person);
				break;
			case HATED_NUMBER:
				addPersonIndexHatedNumber(people, person);
				break;
			case SKILL_LEVEL:
				addPersonIndexSkillLevel(people, person);
				break;
			default:
				throw std::invalid_argument("Unknown indexing key.");
			}
		}
		in.close();
	}
	else {
		throw("Could not find file \"" + fileName + "\" :(");
	}
}

void ReadPersonData(TreeMap<std::string, BinaryTree<Person>>& people, const std::string& fileName) {
	ifstream in(fileName);
	// skip headers...
	std::string next = "";
	std::getline(in, next, '\n');
	if(in) {
		next = "";
		while(!in.eof()) {
			Person person = LoadPersonData(in);
			std::getline(in, next, '\n'); // gets rid of any new line characters at the end
			addPersonIndexName(people, person);
		}
		in.close();
	}
	else {
		throw("Could not find file \"" + fileName + "\" :(");
	}
}

void SplitLoopChar(TreeMap<char, BinaryTree<Person>>& people){
	bool run = true;
	while(run) {
		int ans;
		std::cout << "1. View value by key.\n0. Quit.\n> ";
		std::cin >> ans;
		std::string line;
		switch(ans) {
		case 1:
			char key;
			
			std::cout << "Enter the key you would like to look at:\n> ";
			std::cin >> line;
			key = line[0];
			try {
				std::cout << people.get(key);
			}
			catch(const std::logic_error&) {
				std::cout << "\nThere is no key for " << key << ".";
			}

			std::cout << "\n=====\n";
			break;
		case 0:
			run = false;
			break;
		default:
			break;
		}
		
	}
}
void SplitLoopInt(TreeMap<int, BinaryTree<Person>>& people) {
	bool run = true;
	while(run) {
		int ans;
		std::cout << "1. View value by key.\n0. Quit.\n> ";
		std::cin >> ans;
		std::string line;
		switch(ans) {
		case 1:
			int key;

			std::cout << "Enter the key you would like to look at:\n> ";
			std::cin >> line;
			key = std::stoi(line);
			try {
				std::cout << people.get(key);
			}
			catch(const std::logic_error&) {
				std::cout << "\nThere is no key for " << key << ".";
			}

			std::cout << "\n=====\n";
			break;
		case 0:
			run = false;
			break;
		default:
			break;
		}

	}
}

void SplitLoopString(TreeMap<std::string, BinaryTree<Person>>& people) {
	bool run = true;
	while(run) {
		int ans;
		std::cout << "1. View value by key.\n0. Quit.\n> ";
		std::cin >> ans;
		std::string key;
		switch(ans) {
		case 1:

			std::cout << "Enter the name you would like to look at:\n> ";
			std::cin.ignore();
			std::getline(std::cin, key);
			try {
				std::cout << people.get(key);
			}
			catch(const std::logic_error&) {
				std::cout << "\nThere is no key for " << key << ".";
			}

			std::cout << "\n=====\n";
			break;
		case 0:
			run = false;
			break;
		default:
			break;
		}

	}
}


void StartCSVSplit() {
	TreeMap<std::string, BinaryTree<Person>> people;
	ReadPersonData(people, getFileName());
	people.print();
}

void StartCSVSplitAdvanced() {
	

	std::string fileName = getFileName();

	cout << "Select Index...\n1. Skill Level.\n2. Times played Sonic 2\n3. Favourite Number.\n4. Least Favourite Number.\n5. Name.\n> ";
	int ans;
	cin >> ans;
	IndexKeys key;
	switch(ans) {
	case 1:{
		TreeMap<char, BinaryTree<Person>> people;
		ReadPersonData(people, fileName, SKILL_LEVEL);
		people.print();
		SplitLoopChar(people);
		break;
	}
	case 2: {
		TreeMap<int, BinaryTree<Person>> people;
		ReadPersonData(people, fileName, TIMES_PLAYED_SONIC2);
		people.print();
		SplitLoopInt(people);
		break;
	}
	case 3:{
		TreeMap<int, BinaryTree<Person>> people;
		ReadPersonData(people, fileName, FAVOURITE_NUMBER);
		people.print();
		SplitLoopInt(people);
		break;
	}
	case 4:{
		TreeMap<int, BinaryTree<Person>> people;
		ReadPersonData(people, fileName, HATED_NUMBER);
		people.print();
		SplitLoopInt(people);
		break;
	}
	case 5:{
		TreeMap<std::string, BinaryTree<Person>> people;
		ReadPersonData(people, fileName);
		people.print();
		SplitLoopString(people);
		return;
	}
	default:
		return;
	}

}

void SplitCSVMain() {
	bool run = true;
	while(run) {
		std::cout << "===== LOAD CSV =====\n1: Load File. (Loads a file and shows the output)\n2: Load File Advanced. (Loads a file with more settings)\n0: Quit. (Returns to the Main Menu)\n> ";
		int ans = 0;
		std::cin >> ans;
		switch(ans) {
		case 1:
			StartCSVSplit();
			break;
		case 2:
			StartCSVSplitAdvanced();
			break;
		case 0:
			run = false;
			break;
		default:
			break;
		}
	}
}