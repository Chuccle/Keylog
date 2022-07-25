#pragma once

#include <vector>
#include <memory>
#include <fstream>
#include <iostream>



class FileConverter
{

private:

	std::vector<int> keyAttempt;

	std::vector<std::vector<int>> finput;

	bool duplicateCheck(std::vector<int> vecBuf);

public:

	// Accepts a file directory as a string and returns a vector of vectors of integers
	std::vector<std::vector<int>> parse(const std::string& filename);

};

