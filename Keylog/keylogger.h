#pragma once

#include <unordered_set>
#include <vector>


class Keylogging
{


private:

	std::unordered_set<int> passcodeSet;

	std::vector<std::vector<int>> inputArray;

	int UB;



	// Helper functions, will mutate passcodeSet
	void populateSet();

	void identifyFirst();

	void identifySecond();

	void identifyRest();


public:

	// Accepts a vector of vectors of integers as input, and returns an unordered set.
	std::unordered_set<int> compute(std::vector<std::vector<int>> const& input);


};




