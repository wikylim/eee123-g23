#include <iostream>
#include <fstream>
#include <string>



int main() {
    std::string folderName;
    std::string filename;

    while (true) {
        // Display a prompt to enter the folder name
        std::cout << "Enter the folder name: ";
        std::getline(std::cin, folderName);

        // Display a prompt to enter the file name
        std::cout << "Enter the name of the file to open in the folder '" << folderName << "': ";
        std::getline(std::cin, filename);

        // Open the file with the specified folder and file names
        std::ifstream file(folderName + "/" + filename);

        if (file.is_open()) {
            // File opened successfully, break out of the loop
            break;
        } else {
            // Error opening file
            std::cerr << "Error opening file: " << folderName << "/" << filename << std::endl;

            // Ask the user to input again
            std::cout << "Please try again." << std::endl;
        }
    }

    // Read and print the content line by line
    std::cout << "Raw Data:" << std::endl;
    std::string line;
    std::ifstream file(folderName + "/" + filename); // Open the file again for reading

    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    // Close the file
    file.close();





int sorted_data1[3]={1,2,3};
int sorted_data2[3]={4,5,6};
int sorted_data3[3]={7,8,9};

int final_data[6][6]={
                        {0,0,0,0,0,0},
                        {0,0,0,0,0,0},
                        {0,0,0,0,0,0},
                        {0,0,0,0,0,0},
                        {0,0,0,0,0,0},
                        {0,0,0,0,0,0}};



    // Print the retrieved data to the terminal
    std::cout << "Processed data: " << std::endl;
    std::cout << "Sorted data 1: " << sorted_data1[3] << std::endl;
    std::cout << "Sorted data 2: " << sorted_data2[3] << std::endl;
    std::cout << "Sorted data 3: " << sorted_data3[3] << std::endl;

    std::cout << "Final data: " << final_data[6][6] << std::endl;







    // Open a file for writing
    std::ofstream outputFile("output.txt");

    if (!outputFile.is_open()) {
        // Error opening file
        std::cerr << "Error opening file for writing." << std::endl;
        return 1;
    }

    // Redirect std::cout to the file
    std::streambuf *originalStdout = std::cout.rdbuf();
    std::cout.rdbuf(outputFile.rdbuf());

    // Save all data to the file
    std::cout << "Raw Data:" << std::endl;
    file.open(folderName + "/" + filename);
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();

    std::cout << "Processed Data:" << std::endl;
    std::cout << "Sorted data 1: " << sorted_data1 << std::endl;
    std::cout << "Sorted data 2: " << sorted_data2 << std::endl;
    std::cout << "Sorted data 3: " << sorted_data3 << std::endl;

    std::cout << "Final data: " << final_data << std::endl;


    // Restore std::cout to the original buffer
    std::cout.rdbuf(originalStdout);

    // Close the file
    outputFile.close();

    std::cout << "Program output has been written to 'output.txt'." << std::endl;

    return 0;
}