#pragma once

#include <unordered_set>
#include <vector>


class Keylogging
{


private:

	std::unordered_set<int> passcodeSet;

	std::vector<std::vector<int>> inputArray;

	int UB = 0;

	// Helper functions, will mutate passcodeSet
	void populateSet();

	void identifyFirst();

	void identifySecond();

	void identifyRest();

	bool checkRelativePos(int num);

public:

	// Accepts a vector of vectors of integers as input, and returns an unordered set.
	std::unordered_set<int> compute(const std::vector<std::vector<int>>& input);

};




