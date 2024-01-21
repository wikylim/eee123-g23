#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

void displayMatrix(const vector<vector<int>>& matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        cout << " | D" << (i + 1) << " ";
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << "|\n";
    }
}

int main(){

    int rows_d = 8; // Rows for D
    int cols = 8;   // Columns for R1 to R8

    //raw data
    cout << "raw1>> {{0, 0}, {100, 98}, {99, 99}, {100, 99}, {101, 99}, {98, 100}, {99, 100}, {100, 100}, {101, 100}, {102, 100}, {97, 101}, {98, 101}, {99, 101}, {100, 101}, {101, 101}, {102, 101}, {103, 101}, {98, 102}, {99, 102}, {100, 102}, {101, 102}, {102, 102}, {99, 103}, {100, 103}, {101, 103}, {100, 104}, {600, 197}, {599, 198}, {600, 198}, {601, 198}, {598, 199}, {599, 199}, {600, 199}, {601, 199}, {602, 199}, {597, 200}, {598, 200}, {599, 200}, {600, 200}, {601, 200}, {602, 200}, {603, 200}, {598, 201}, {599, 201}, {600, 201}, {601, 201}, {602, 201}, {599, 202}, {600, 202}, {601, 202}, {600, 203}, {300, 297}, {299, 298}, {300, 298}, {301, 298}, {298, 299}, {299, 299}, {300, 299}, {301, 299}, {302, 299}, {297, 300}, {298, 300}, {299, 300}, {300, 300}, {301, 300}, {302, 300}, {303, 300}, {298, 301}, {299, 301}, {300, 301}, {301, 301}, {302, 301}, {299, 302}, {300, 302}, {301, 302}, {300, 303}, {400, 497}, {399, 498}, {400, 498}, {401, 498}, {398, 499}, {399, 499}, {400, 499}, {401, 499}, {402, 499}, {397, 500}, {398, 500}, {399, 500}, {400, 500}, {401, 500}, {402, 500}, {403, 500}, {398, 501}, {399, 501}, {400, 501}, {401, 501}, {402, 501}, {399, 502}, {400, 502}, {401, 502}, {400, 503}}" << endl;
    cout << "raw2>> {{0, 0}}" << endl;
    cout << "raw3>> {{0, 0}}" << endl;
    cout<<endl;

    //sorted data
    cout<<"sort..."<<endl;
    cout<<"sorted_data1: ";
    cout<<"{";
    int sorted_data1[3]={1,2,3};
    for(int i=0;i<3;i++){
        std::cout<<sorted_data1[i];
        if (i<2){
            cout<<", ";
        }
    }
        cout<<"}"<<endl;
        
        cout<<"sorted_data2: ";
        cout<<"{";
    int sorted_data2[3]={4,5,6};
    for(int i=0;i<3;i++){
        std::cout<<sorted_data2[i];
        if (i<2){
            cout<<", ";
        }
    }
        cout<<"}"<<endl;
    cout<<"sorted_data3: ";
    cout<<"{";
    int sorted_data3[3]={7,8,9};
    for(int i=0;i<3;i++){
        std::cout<<sorted_data3[i];
        if (i<2){
            cout<<", ";
        }
    }
        cout<<"}"<<endl;
        cout<<endl;





//final data
    cout << "final_data: " << endl;
cout << "{" << endl;
int final_data[8][8] = {{1, 2, 3, 4, 5, 6, 7, 8},
                        {9, 10, 11, 12, 13, 14, 15, 16},
                        {17, 18, 19, 20, 21, 22, 23, 24},
                        {25, 26, 27, 28, 29, 30, 31, 32},
                        {33, 34, 35, 36, 37, 38, 39, 40},
                        {41, 42, 43, 44, 45, 46, 47, 48},
                        {49, 50, 51, 52, 53, 54, 55, 56},
                        {57, 58, 59, 60, 61, 62, 63, 64}};

for (int i = 0; i < 8; i++) {
    cout << "   {";
    for (int j = 0; j < 8; j++) {
        cout << setw(2) << final_data[i][j];
        if (j < 7) {
            cout << ", ";
        }
    }
    cout << "}";
    if (i < 7) {
        cout << "," << endl;
    }
}
cout << endl;
cout << "}" << endl;
cout << endl;

    
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


//outputfile

    ofstream outputfile ("output.txt");
    if(outputfile.is_open()){
          //raw data
    outputfile<<"raw1>> [(0, 0), (100, 98), (99, 99), (100, 99), (101, 99), (98, 100), (99, 100), (100, 100), (101, 100), (102, 100), (97, 101), (98, 101), (99, 101), (100, 101), (101, 101), (102, 101), (103, 101), (98, 102), (99, 102), (100, 102), (101, 102), (102, 102), (99, 103), (100, 103), (101, 103), (100, 104), (600, 197), (599, 198), (600, 198), (601, 198), (598, 199), (599, 199), (600, 199), (601, 199), (602, 199), (597, 200), (598, 200), (599, 200), (600, 200), (601, 200), (602, 200), (603, 200), (598, 201), (599, 201), (600, 201), (601, 201), (602, 201), (599, 202), (600, 202), (601, 202), (600, 203), (300, 297), (299, 298), (300, 298), (301, 298), (298, 299), (299, 299), (300, 299), (301, 299), (302, 299), (297, 300), (298, 300), (299, 300), (300, 300), (301, 300), (302, 300), (303, 300), (298, 301), (299, 301), (300, 301), (301, 301), (302, 301), (299, 302), (300, 302), (301, 302), (300, 303), (400, 497), (399, 498), (400, 498), (401, 498), (398, 499), (399, 499), (400, 499), (401, 499), (402, 499), (397, 500), (398, 500), (399, 500), (400, 500), (401, 500), (402, 500), (403, 500), (398, 501), (399, 501), (400, 501), (401, 501), (402, 501), (399, 502), (400, 502), (401, 502), (400, 503)]"<<endl;
    outputfile<<"raw2>> "<<endl;
    outputfile<<"raw3>> "<<endl;
    outputfile<<endl;

    //sorted data
    outputfile<<"sort..."<<endl;
    outputfile<<"sorted_data1: ";
    outputfile<<"{";
    int sorted_data1[3]={1,2,3};
    for(int i=0;i<3;i++){
        outputfile<<sorted_data1[i];
        if (i<2) {
            outputfile<<", ";
        }
    }
        outputfile<<"}";
        outputfile<<endl;
        

        outputfile<<"sorted_data2: ";
        outputfile<<"{";
    int sorted_data2[3]={4,5,6};
    for(int i=0;i<3;i++){
        outputfile<<sorted_data2[i];
        if (i<2) {
            outputfile<<", ";
        }
    }
    outputfile<<"}";

        outputfile<<endl;
    outputfile<<"sorted_data3: ";
    outputfile<<"{";
    int sorted_data3[3]={7,8,9};
    for(int i=0;i<3;i++){
        outputfile<<sorted_data3[i];   
        if (i<2) {
            outputfile<<", ";
        }
    }
    outputfile<<"}";

    outputfile<<endl;
    outputfile<<endl;

    outputfile<<"___________________________________Final output____________________________________________________"<<endl;
    //final data
    outputfile << "final_data: " << endl;
    outputfile << "{" << endl;
    
    int final_data[8][8] = {{1, 2, 3, 4, 5, 6, 7, 8},
                            {9, 10, 11, 12, 13, 14, 15, 16},
                            {17, 18, 19, 20, 21, 22, 23, 24},
                            {25, 26, 27, 28, 29, 30, 31, 32},
                            {33, 34, 35, 36, 37, 38, 39, 40},
                            {41, 42, 43, 44, 45, 46, 47, 48},
                            {49, 50, 51, 52, 53, 54, 55, 56},
                            {57, 58, 59, 60, 61, 62, 63, 64}};

    for (int i = 0; i < 8; i++) {
        outputfile << "   {";
        for (int j = 0; j < 8; j++) {
            outputfile << setw(2) << final_data[i][j];
            if (j < 7) {
                outputfile << ", ";
            }
        }
        outputfile << "}";
        if (i < 7) {
            outputfile << "," << endl;
        }
    }
    
    outputfile << endl;
    outputfile << "}" << endl;
    outputfile << endl;

    // Display the matrix headers
    outputfile << "|   | R1  R2  R3  R4  R5  R6  R7  R8 |\n";

    // Display the combined matrix with set indicators
    for (int i = 0; i < rows_d; ++i) {
        outputfile << "| D" << (i + 1) << " ";
        for (int j = 0; j < cols; ++j) {
            // Display 1, 2, or 3 based on which set has data at this position
            if (matrix1[i][j] > 0) {
                outputfile << setw(3) << 1 << " ";
            } else if (matrix2[i][j] > 0) {
                outputfile << setw(3) << 2 << " ";
            } else if (matrix3[i][j] > 0) {
                outputfile << setw(3) << 3 << " ";
            } else {
                outputfile << setw(3) << 0 << " ";
            }
        }
        outputfile << "|\n";
    }

//close output.txt
    outputfile.close();
    }else{
        cerr<<"unable to open file for writing."<<endl;
    }
    
    return 0;

}
