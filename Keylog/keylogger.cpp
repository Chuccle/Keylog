#include "keylogger.h"
#include <iostream>


// Expensive return and input so we make use of reference variables
std::unordered_set<int> Keylogging::compute(const std::vector<std::vector<int>>& input) {

	inputArray = input;

	populateSet();

	// Removes warning because we are assigning an int from a long long
	UB = (int)passcodeSet.size();

	identifyFirst();

	identifySecond();

	identifyRest();

	return passcodeSet;

}


void Keylogging::populateSet() {

	for (int j = 0; j < inputArray.size(); j++) {

		for (int k = 0; k < inputArray[j].size(); k++) {

			// Loop through every element in the array, populate set with all possible values
			passcodeSet.insert(inputArray[j][k]);

		}

	}

};


void Keylogging::identifyFirst() {

	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < inputArray.size(); j++) {

			for (int k = 0; k < inputArray[j].size(); k++) {

				// Determines first number since first number is only at index 0

				// If not then delete the number from the passcodeSet

				if (inputArray[j][1] == i || inputArray[j][2] == i) {

					passcodeSet.erase(i);

				}

			}

		}

	}


};


void Keylogging::identifySecond() {

	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < inputArray.size(); j++) {

			// We can determine that the second number will always be at index 1
			if (inputArray[j][1] == i) {

				// We only want to find numbers that have the same first number as the first number in the sequence
				if (!passcodeSet.contains(inputArray[j][0])) {

					break;

				}

				passcodeSet.insert(i);

				return;

			}

		}

	}

};


void Keylogging::identifyRest() {

	// Uses the maximum size of the passcodeSet determined from populateSet()
	if (passcodeSet.size() == UB) {
		return;
	}


	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < inputArray.size(); j++) {

			// If a number exists at the end of a sequence
			if (inputArray[j][2] == i) {


				if (checkRelativePos(i)) {

					passcodeSet.insert(i);

				}


				break;
			}

		}

	}

	// Recur until we have all numbers in the passcodeSet
	identifyRest();

};


bool Keylogging::checkRelativePos(int num) {

	// Loops through the entirety of inputArray to ensure the number is not preceded by numbers that are not in the passcodeSet.
	for (int i = 0; i < inputArray.size(); i++) {

		if (inputArray[i][2] == num) {

			if (!(passcodeSet.contains(inputArray[i][0])
				&& (passcodeSet.contains(inputArray[i][1])))) {

				return false;

			}

		}

	}

	return true;

}



