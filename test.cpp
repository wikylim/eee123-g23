#include <iostream>
#include <fstream>
#include <cctype>

int countContiguousNumbers(const std::string& filename) {
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return -1;
    }

    char currentChar;
    bool inNumber = false;
    int count = 0;

    while (inputFile.get(currentChar)) {
        if (std::isdigit(currentChar)) {
            // If the character is a digit, and we are not already in a number, start counting a new number
            if (!inNumber) {
                inNumber = true;
                count++;
            }
        } else {
            // If the character is not a digit, mark the end of the current number
            inNumber = false;
        }
    }

    inputFile.close();
    return count;
}

int main() {
    std::string filename = "raw1.txt";  // Replace with the actual file path

    int numberOfNumbers = countContiguousNumbers(filename);

    if (numberOfNumbers >= 0) {
        std::cout << "Number of contiguous numbers in the file: " << numberOfNumbers << std::endl;
    }

    return 0;
}
