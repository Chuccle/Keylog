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


public:

	// Accepts a file directory as a string and returns a vector of vectors of integers
	std::vector<std::vector<int>> parse(std::string const& filename);

};

