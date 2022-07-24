// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "Keylogger.h"
#include "FileConverter.h"


int main()
{

	// Minimum length password = 5 characters

	FileConverter fileConverter;

	Keylogging keylogger;

	std::vector<std::vector<int>> finput = fileConverter.parse("C:/Users/charl/Source/Repos/Keylog/tests/test.txt");

	std::unordered_set test = keylogger.compute(finput);

	for (int const& inner : test)
	{
		std::cout << inner << ' ';

	}

}

