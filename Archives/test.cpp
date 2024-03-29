#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#define vector std::vector


int main() {


    vector<vector<vector<int>>> xcoord(3, vector<vector<int>>(6, vector<int>(1)));

    for(int i=0;i<3;i++){
        for(int j=0;j<6;j++){
            xcoord[i][j][j] = j+1;
            xcoord[i][j].resize(j+1);
            xcoord[i][j][j] = j+1;
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<6;j++){
            for(int k=0;k<xcoord[i][j].size();k++){
                cout << xcoord[i][j][k] << " ";
            }
        cout << "\n";
        }
        cout << "\n";
    }


    return 0;
}

/*

 int dataA[6][6] = {{/* your data for dataA }};
    int dataB[6][6] = {{/* your data for dataB }};
    int dataC[6][6] = {{/* your data for dataC }};

    // Write dataA to file
    writeDataToFile("output.txt", dataA);

    // Append dataB to the same file
    writeDataToFile("output.txt", dataB);

    // Append dataC to the same file
    writeDataToFile("output.txt", dataC);

    std::cout << "Data has been written to output.txt" << std::endl;

const int numRows = 6;
const int numCols = 6;

void writeDataToFile(const char* fileName, int data[][numCols]) {
    // Open the file
    std::ofstream outputFile(fileName);

    // Check if the file is open
    if (!outputFile.is_open()) {
        std::cerr << "Error opening the file: " << fileName << std::endl;
        return;
    }

    // Write the array contents to the file
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            outputFile << data[i][j] << " ";
        }
        outputFile << std::endl;
    }

    // Close the file
    outputFile.close();
}



*/







/*#include <iostream>
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
*/