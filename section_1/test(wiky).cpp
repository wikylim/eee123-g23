#include <iostream>
#include <fstream>

int main() {
    // Open the file
    std::ifstream inputFile("raw1.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    // Assuming a maximum of 100 points for arrayRaw1
    const int maxPoints = 100;
    int arrayRaw1[maxPoints][2];
    int count = 0; // Counter for the number of points read

    // Read the file content
    std::string line;
    while (std::getline(inputFile, line)) {
        size_t start = line.find("(");
        size_t end = line.find(")");

        while (start != std::string::npos && end != std::string::npos) {
            // Extracting the numbers between parentheses
            std::string point = line.substr(start + 1, end - start - 1);

            // Extracting x and y coordinates
            int x, y;
            sscanf(point.c_str(), "%d, %d", &x, &y);

            // Storing the values in the array
            if (count < maxPoints) {
                arrayRaw1[count][0] = x;
                arrayRaw1[count][1] = y;
                count++;
            }

            // Move to the next point
            start = line.find("(", end);
            end = line.find(")", start);
        }
    }

    // Close the file
    inputFile.close();

    // Print the extracted values
    for (int i = 0; i < count; i++) {
        std::cout << arrayRaw1[i][0] << ", " << arrayRaw1[i][1] << std::endl;
    }

    return 0;
}
