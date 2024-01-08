#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
};

// Function to read text files and store data in a vector of points
vector<Point> readTextFile(const string& filePath) {
    vector<Point> points;
    ifstream input_file(filePath);

    if (!input_file.is_open()) {
        cerr << "\nCouldn't open the file: '" << filePath << "'\n";
        exit(EXIT_FAILURE);
    }

    char line;
    int number;
    while (input_file >> line >> number) {
        Point p;
        p.x = number;
        input_file >> line >> p.y;
        points.push_back(p);
    }

    input_file.close();
    return points;
}

// Comparison function to sort points based on y-coordinate
bool comparePoints(const Point& a, const Point& b) {
    return a.y < b.y;
}

int main() {
    string folderPath;
    
    cout << "\nEnter the file location.\n"
         << "Eg: \"C:\\Programming_MiniProject\\rawdata\\set 1\n"
         << "Folder location: ";
    getline(cin, folderPath);

    // Set the array number for each raw data
    for (int set = 1; set <= 3; set++) {
        string filePath = folderPath + "\\raw" + to_string(set) + ".txt";

        // Read and store data in a vector of points
        vector<Point> points = readTextFile(filePath); 

        // Sort the vector based on y-coordinate
        sort(points.begin(), points.end(), comparePoints);

        // Print sorted data
        cout << "\n\nSorted y-coordinate for raw " << set << "\n";
        for (const auto& point : points) {
            cout << "(" << point.x << " , " << point.y << ") ";
        }
    }

    return 0;
}
