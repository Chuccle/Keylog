// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include "Keylogger.h"


int main()
{

	// 2D array helps when deconstructing each sequence.

	// TODO:

	// Ensure that the file is not empty and also only contains valid characters.
	// Use file directory as parameter.
	// restructure and validation of input file
	// check for duplicate elements within an attempt

	std::vector<int> keyAttempt;

	std::vector<std::vector<int>> finput;


	//lives as long as scope

	std::unique_ptr<std::fstream> my_file(new std::fstream);

	Keylogging k;

	my_file->open("C:/Users/charl/Source/Repos/Keylog/tests/test2.txt", std::ios::in);

	char ch;

	// iterate until end of file
	while (1)

	{

		if (my_file->eof()) {

			if (keyAttempt.size() == 3) {


				finput.push_back(keyAttempt);

				keyAttempt.clear();

			}


			break;

		}



		// read a character and adsign it to the ch
		my_file->get(ch);


		// if the character is a number, add it to the keySequence vector
		if (ch != '\n')
		{

			// we have to recast the char to an int

			// We append the character to the end of the keySequence vector

			keyAttempt.push_back(atoi(&ch));

		}
		// delimit our vector by newlines
		else {



			if (keyAttempt.size() < 3) {


				break;

			}



			for (int i = 0; i < 3; i++) {

				std::cout << keyAttempt[i] << std::endl;


			}

			// if array is empty or not full, we don't want to add it to the array.


			// we then add the keySequence vector to the finput 2d vector
			finput.push_back(keyAttempt);


			// clear the keySequence vector
			keyAttempt.clear();


		}

	}

	my_file->close();

	std::unordered_set test = k.compute(finput);

	for (int const& swag : test)
	{
		std::cout << swag << ' ';

	}


}

