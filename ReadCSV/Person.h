#pragma once

#include <iostream>
#include <string>

struct Person {

	std::string name;
	int favouriteNumber, hatedNumber, timesPlayedSonic2;
	bool isAContrarian;
	char skillLevel;

	Person(const std::string name, const int timesPlayedSonic2, const int favNum, const int hatedNum, const std::string contrarian, const char skillLevel) {
		this->name = name;
		this->timesPlayedSonic2 = timesPlayedSonic2;
		this->favouriteNumber = favNum;
		this->hatedNumber = hatedNum;
		this->isAContrarian = (contrarian == "Yes") ? true: false;
		this->skillLevel = skillLevel;
	}
	Person(const std::string name, const bool timesPlayedSonic2, const int favNum, const int hatedNum, const bool contrarian, const char skillLevel) {
		this->name = name;
		this->timesPlayedSonic2 = timesPlayedSonic2;
		this->favouriteNumber = favNum;
		this->hatedNumber = hatedNum;
		this->isAContrarian = contrarian;
		this->skillLevel = skillLevel;
	}
	Person() {
		this->name = "name";
		this->timesPlayedSonic2 = 0;
		this->favouriteNumber = 0;
		this->hatedNumber = 10;
		this->isAContrarian = false;
		this->skillLevel = 'E';
	}

	bool operator==(Person& person) { return this->name == person.name; }
	bool operator<(Person& person) { return this->name < person.name; }
	bool operator>(Person& person) { return this->name > person.name; }

	friend std::ostream& operator<<(std::ostream& out, const Person& person) {
		out << "\n{ \"" << person.name << "\", " << person.timesPlayedSonic2 << ", " << person.favouriteNumber << ", " << person.hatedNumber << ", " << person.isAContrarian << ", " << person.skillLevel << " }";
		return out;
	}
};