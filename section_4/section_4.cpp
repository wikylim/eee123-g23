//welcome...
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


// Function to convert (x, y) data coordinates into matrix form
vector<vector<double>> convertToMatrix(const vector<pair<double, double>>& data)
{
    vector<vector<double>> matrix;
    for (const auto& point : data)
    {
        matrix.push_back({point.first, point.second});
    }
    return matrix;
}

int main() {
    string inputFileName, outputFileName;

    // Get input and output file names from the user
    cout << "Enter input file name: ";
    cin >> inputFileName;

    // Open the input file
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open())
    {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    // Read data from the input file
    vector<pair<double, double>> rawData;
    double x, y;
    while (inputFile >> x >> y)
    {
        rawData.push_back({x, y});
    }

    // Display raw data
    cout << "Raw Data:" << endl;
    for (const auto& point : rawData)
    {
        cout << "(" << point.first << ", " << point.second << ")" << endl;
    }

    // Process data
    vector<vector<double>> processedData = convertToMatrix(rawData);

    // Display processed data (matrix form)
    cout << "Matrix Form:" << endl;
    cout << "| |R1|R2|R3|R4|R5|R6|NS|" << endl;
    for (const auto& row : processedData)
    {
        for (const auto& element : row)
        {
            cout << element << " ";
        }
        cout << endl;
    }

    // Write all output to a text file
    size_t dotPosition = inputFileName.find_last_of(".");
    outputFileName = inputFileName.substr(0, dotPosition) + "_output.txt";
    ofstream outputFile(outputFileName);
    if (!outputFile.is_open())
    {
        cerr << "Error opening output file." << endl;
        return 1;
    }

    // Write raw data to file
    outputFile << "Raw Data:" << endl;
    for (const auto& point : rawData)
    {
        outputFile << "(" << point.first << ", " << point.second << ")" << endl;
    }

    // Write processed data to file
    outputFile << "Matrix Form:" << endl;
    outputFile << "| |R1|R2|R3|R4|R5|R6|NS|" << endl;
    for (const auto& row : processedData)
    {
        for (const auto& element : row)
        {
            outputFile << element << " ";
        }
        outputFile << endl;
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    return 0;
}