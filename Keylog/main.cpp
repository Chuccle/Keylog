// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "Keylogger.h"
#include "FileConverter.h"


int main()
{

	FileConverter fileConverter;

	Keylogging keylogger;

	std::vector<std::vector<int>> finput = fileConverter.parse("C:/Users/charl/Source/Repos/Keylog/tests/test2.txt");

	std::unordered_set test = keylogger.compute(finput);

	std::cout << test.size() << std::endl;

	for (int const& inner : test)
	{
		std::cout << inner;

	}

}

