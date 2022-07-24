#include "keylogger.h"
#include <iostream>



struct Data {


	std::unordered_set<int> passcodeSet;

	std::vector<std::vector<int>> inputArray;

	int UB;

};


std::unordered_set<int> Keylogging::compute(std::vector<std::vector<int>> const& input) {


	inputArray = input;

	populateSet();

	UB = passcodeSet.size();

	identifyFirst();

	identifySecond();

	identifyRest();

	return passcodeSet;

}


void Keylogging::populateSet() {


	for (int j = 0; j < inputArray.size(); j++) {

		for (int k = 0; k < inputArray[k].size(); k++) {
			//loop through every element in the array, populate set with all possible values

			passcodeSet.insert(inputArray[j][k]);

		}

	}

};


void Keylogging::identifyFirst() {


	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < inputArray.size(); j++) {

			for (int k = 0; k < inputArray[k].size(); k++) {

				//determines first number since first number is only at index 0

				//if not then delete the number from the passcodeSet

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


			if (inputArray[j][1] == i) {


				// we only want to find numbers that have the same first number as the first number in the sequence
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

	//base condition. assumes we use every number possibility.

	if (passcodeSet.size() == UB) {
		return;
	}


	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < inputArray.size(); j++) {


			if (inputArray[j][2] == i) {


				// guard clause which continues loop if the passcodeSet doesn't contain both the first and second number in the current sequence
				if (!(passcodeSet.contains(inputArray[j][0]) && (passcodeSet.contains(inputArray[j][1])))) {

					//exit inner loop to iterate outer. Didn't want to use Goto.
					break;


				}


				if (checkRelativePos(i)) {
					passcodeSet.insert(i);
				}


				break;
			}

		}

	}

	//recurse until we have all numbers in the passcodeSet

	identifyRest();

};




bool Keylogging::checkRelativePos(int num) {


	for (int j = 0; j < inputArray.size(); j++) {

		if (inputArray[j][2] == num) {

			if (!(passcodeSet.contains(inputArray[j][0]) && (passcodeSet.contains(inputArray[j][1])))) {

				return false;

			}

		}

	}




	return true;

}



