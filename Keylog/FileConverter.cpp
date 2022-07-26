#include "FileConverter.h"
#include <algorithm>
#include <unordered_set>

// Expensive return and input so we make use of reference variables
std::vector<std::vector<int>> FileConverter::parse(const std::string& filename)
{

	// Unordered set is constant whereas normal set is (log(n))
	std::unordered_set <char> acceptableChars{
		'0',
		'1',
		'2',
		'3',
		'4',
		'5',
		'6',
		'7',
		'8',
		'9'
	};

	// Could be too big for stack?
	std::unique_ptr<std::fstream> file(new std::fstream);

	file->open(filename, std::ios::in);

	if (file->fail())
	{
		std::cout << "File not found" << std::endl;
		exit(EXIT_FAILURE);

	}



	char ch;

	while (1)

	{

		// Iterate until end of file
		if (file->eof()) {

			break;
		}


		// Read a character and assign it to the ch
		file->get(ch);


		if (keyAttempt.size() == 3) {

			if (duplicateCheck(keyAttempt)) {

				std::cout << "Duplicate elements in sequence at sequence " << finput.size() + 1;
				exit(EXIT_FAILURE);

			}

			// We then add the keySequence vector to the finput 2d vector
			finput.push_back(keyAttempt);

			// Clear the keySequence buffer vector
			keyAttempt.clear();

		}

		// We only want characters that are numbers 0-9
		if (acceptableChars.contains(ch))
		{

			// We have to recast the char to an int
			// We append the character to the end of the keySequence vector
			keyAttempt.push_back(atoi(&ch));

		}

	}



	if (finput.empty()) {

		std::cout << "No sequences found" << std::endl;
		exit(EXIT_FAILURE);
	}



	return finput;
}


bool FileConverter::duplicateCheck(std::vector<int> vecBuf) {

	// We sort the vector, which will pair duplicate elements together
	std::sort(vecBuf.begin(), vecBuf.end());

	// We then iterate through the vector second and third elements and check if an element is equal to the previous element
	for (int i = 1; i < vecBuf.size(); i++) {

		if (vecBuf[i] == vecBuf[i - 1]) {

			return true;
		}
	}

	return false;

}