#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void displayMatrix(const vector<vector<int>>& matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        cout << "| D" << (i + 1) << " ";
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << "|\n";
    }
}

int main() {
    int rows_d = 8; // Rows for D
    int cols = 8;   // Columns for R1 to R8

    // Initialize matrices for each set with zeros
    vector<vector<int>> matrix1(rows_d, vector<int>(cols, 0));
    vector<vector<int>> matrix2(rows_d, vector<int>(cols, 0));
    vector<vector<int>> matrix3(rows_d, vector<int>(cols, 0));

    // Input data for three sets in the form of (x, y)
    vector<vector<pair<int, int>>> allCoordinates = {
        // Set 1
        {{0, 0}, {400, 97}, {399, 98}, {400, 98}, {401, 98}, {398, 99}, {399, 99}, {400, 99}, {401, 99}, {402, 99}, {397, 100}, {398, 100}, {399, 100}, {400, 100}, {401, 100}, {402, 100}, {403, 100}, {398, 101}, {399, 101}, {400, 101}, {401, 101}, {402, 101}, {399, 102}, {400, 102}, {401, 102}, {400, 103}},
        // Set 2
        {{0, 0}, {300, 397}, {299, 398}, {300, 398}, {301, 398}, {298, 399}, {299, 399}, {300, 399}, {301, 399}, {302, 399}, {297, 400}, {298, 400}, {299, 400}, {300, 400}, {301, 400}, {302, 400}, {303, 400}, {298, 401}, {299, 401}, {300, 401}, {301, 401}, {302, 401}, {299, 402}, {300, 402}, {301, 402}, {300, 403}},
        // Set 3
        {{0, 0}, {99, 298}, {100, 298}, {101, 298}, {98, 299}, {99, 299}, {100, 299}, {101, 299}, {102, 299}, {98, 300}, {99, 300}, {100, 300}, {101, 300}, {102, 300}, {98, 301}, {99, 301}, {100, 301}, {101, 301}, {102, 301}, {99, 302}, {100, 302}, {101, 302}, {499, 498}, {500, 498}, {501, 498}, {498, 499}, {499, 499}, {500, 499}, {501, 499}, {502, 499}, {498, 500}, {499, 500}, {500, 500}, {501, 500}, {502, 500}, {498, 501}, {499, 501}, {500, 501}, {501, 501}, {502, 501}, {499, 502}, {500, 502}, {501, 502}}
    };

    // Loop through each set of coordinates
    for (size_t setIndex = 0; setIndex < allCoordinates.size(); ++setIndex) {
        const vector<pair<int, int>>& coordinates = allCoordinates[setIndex];

        // Choose the appropriate matrix based on the set index
        vector<vector<int>>& currentMatrix = (setIndex == 0) ? matrix1 : (setIndex == 1) ? matrix2 : matrix3;

        // Update matrix based on input coordinates
        for (auto& coordinate : coordinates) {
            // Calculate row and column indices for D1 to D8
            int row = coordinate.second / 100;
            int col = coordinate.first / 100;

            // Ensure the row and column indices are within bounds
            if (row >= 0 && row < rows_d && col >= 0 && col < cols) {
                currentMatrix[row][col]++;
            }
        }
    }

    // Display the matrix headers
    cout << "|   | R1  R2  R3  R4  R5  R6  R7  R8 |\n";

    // Display the combined matrix with set indicators
    for (int i = 0; i < rows_d; ++i) {
        cout << "| D" << (i + 1) << " ";
        for (int j = 0; j < cols; ++j) {
            // Display 1, 2, or 3 based on which set has data at this position
            if (matrix1[i][j] > 0) {
                cout << setw(3) << 1 << " ";
            } else if (matrix2[i][j] > 0) {
                cout << setw(3) << 2 << " ";
            } else if (matrix3[i][j] > 0) {
                cout << setw(3) << 3 << " ";
            } else {
                cout << setw(3) << 0 << " ";
            }
        }
        cout << "|\n";
    }

    // Display Coordinate Information
    
    cout << "\nCoordinate Information:\n";
    cout << "1 : raw1.txt" << "\n";
    cout << "2 : raw2.txt" << "\n";
    cout << "3 : raw3.txt" << "\n";
    cout << "D" << " : " << "y coordinates" << "\n";
    cout << "R" << " : " << "x coordinates" << "\n";

    for (int i = 0; i < rows_d; ++i) {
        cout << "D" << (i + 1) << " : " << (i * 100) << "-" << ((i + 1) * 100 - 1) << "\n";
    }

    for (int i = 0; i < cols; ++i) {
        cout << "R" << (i + 1) << " : " << (i * 100) << "-" << ((i + 1) * 100 - 1) << "\n";
    }

    return 0;
}



