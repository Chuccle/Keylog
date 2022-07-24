#include "FileConverter.h"


struct Data {

	// Use this vector as a buffer for each line in the file.
	std::vector<int> keyAttempt;

	std::vector<std::vector<int>> finput;

};


std::vector<std::vector<int>> FileConverter::parse(std::string const& filename)
{

	std::unique_ptr<std::fstream> file(new std::fstream);

	file->open(filename, std::ios::in);

	char ch;

	while (1)

	{

		// Iterate until end of file
		if (file->eof()) {

			// Ensure that the latest line is read and stored in the vector
			if (keyAttempt.size() == 3) {

				finput.push_back(keyAttempt);

				keyAttempt.clear();

			}

			break;
		}


		// Read a character and adsign it to the ch
		file->get(ch);

		// If the character is a number, add it to the keySequence vector
		if (ch != '\n')
		{

			// We have to recast the char to an int
			// We append the character to the end of the keySequence vector
			keyAttempt.push_back(atoi(&ch));

		}
		else {

			// If array is empty or not full, we don't want to add it to the array.
			if (keyAttempt.size() < 3) {


				break;

			}

			//TOOD:

			// Check for duplicate elements within the buffer array
			// Check for characters that aren't numbers within the buffer array



			// We then add the keySequence vector to the finput 2d vector
			finput.push_back(keyAttempt);


			// Clear the keySequence vector
			keyAttempt.clear();


		}

	}

	file->close();

	return finput;
}
