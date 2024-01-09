// welcome...
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

#define cout std::cout
#define endl std::endl
#define string std::string

void _sort(int arr[], int size);
void appendMatrix(int arr[], int size, int xloc, int _data[6][6]);
void displayMatrix(int _data[6][6], char _title[], bool toggleClear);
void copyData(int arr1[][2], int rawSize, int rawArr[][2]);
void setData(int _data[6][6], int target);
void closing();

template <std::size_t Rows, std::size_t Cols>
int getIndex(int(&array)[Rows][Cols]){
    return Rows;
}

//----------------------------------------------------------------------------------------------

void copyData(int arr1[][2], int rawSize, int rawArr[][2]){
    for(int i=0;i<rawSize;i++){
    for(int j=0;j<2;j++){
        arr1[i][j] = rawArr[i+1][j];             // skip copying (0, 0)
    }
}
}

void _sort(int arr[], int size){
    for(int i=1;i<size;i++){
        for(int i=0;i<size-1;i++){
            if(arr[i]>arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
}

void appendMatrix(int arr[], int size, int xloc, int _data[6][6]){      // (input data, input data, input data, output data)
//x100A
//int ycoord1[6] = {0, 0, 0, 0, 0, 0};
//int ydifference = 1;
for(int i=0;i<size;i++){
    //ycoord1[indx]++;
    if(arr[i]==0){                                 //filter out (0, 0)
        cout << "EMPTY!!" << endl;
    }
    else{
        int indx = int((round(static_cast<double>(arr[i])/100.0)-1));
        _data[indx][xloc]++;
        }
    }
}

void displayMatrix(int _data[6][6], char _title[], bool toggleClear){
    cout << "------------- M a t r i x   d a t a   f o r   " << _title << " -----------------------\n" << endl;
    cout << "\tR1\tR2\tR3\tR4\tR5\tNS" << endl;
    for(int j=0;j<6;j++){
        if(j<4){
            cout << "D\t";
        }
        else{cout << "R\t";}
        for(int i=0;i<6;i++){
            if(_data[j][i]==0 && toggleClear){cout << "\t";}
            else{cout << _data[j][i] << "\t";}
        }
        cout << "\n";
    }
    cout << "\n---------------------------------------------------------------------------\n";

}

void setData(int _data[6][6], int target){
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(_data[i][j]!=0){
                _data[i][j]=target;
            }
        }
    }
}

void closing(){
    cout << "\n";
    cout << "                       T h a n k   y o u" << endl;
    cout << "\n                 H a v e   a   g o o d   d a y   : ) \n" << endl;
}

int countContiguousNumbers(const string& filename) {
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << filename << endl;
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




// section 1 aydin

void readTextFiles(const string& folderPath, int set) {
    char line;
    string temp ; 
    int number, i=0, j=0, k=0, repeat =0, raw[3][5000][2], change;

    std::ifstream input_file(folderPath);
        //input symbol data
        input_file >> temp;
        input_file >> line;
        //input data to array
        while (input_file >> line){  
            if (input_file >> number){    
                raw[set] [i][j] = number;

                if (j == 0){
                    j = 1; 
                }
                else {
                    j = 0;
                    i++;
                    input_file >> temp;
                    repeat ++;
                }
            }
        }
        input_file.close();

        //print collected data
        cout << "\nInput data("<<set+1<<")"<<endl;
        cout << "[";
        for (i=0 ; i < repeat ; i++){
            j=0;
            cout << "(" <<raw[set] [i][j] << " , " ;
            j = 1;
            cout << raw[set] [i][j] << ") " ; 

        }
        cout << "]"<<endl;
        }


void extractData(const char* fileName, int array[][2], int count, int maxPoints) {
    // Open the file
    std::ifstream inputFile(fileName);

    // Check if the file is open
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file: " << fileName << endl;
        return;
    }

    // Read the file content
    string line;
    

    while (std::getline(inputFile, line)) {
        size_t start = line.find("(");
        size_t end = line.find(")");

        while (start != string::npos && end != string::npos) {
            // Extracting the numbers between parentheses
            string point = line.substr(start + 1, end - start - 1);

            // Extracting x and y coordinates
            int x, y;
            sscanf(point.c_str(), "%d, %d", &x, &y);

            // Storing the values in the array
             if (count < maxPoints) {
            array[count][0] = x;
            array[count][1] = y;
            count++;
            }

            // Move to the next point
            start = line.find("(", end);
            end = line.find(")", start);
        }
    }

    // Close the file
    inputFile.close();
}







/*
const int maxPoints = 50;
void extractData(const char* fileName, int array[][2], int& count) {
    // Open the file
    std::ifstream inputFile(fileName);

    // Check if the file is open
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file: " << fileName << endl;
        return;
    }

    // Read the file content
    string line;
    while (std::getline(inputFile, line)) {
        size_t start = line.find("(");
        size_t end = line.find(")");

        while (start != string::npos && end != string::npos) {
            // Extracting the numbers between parentheses
            string point = line.substr(start + 1, end - start - 1);

            // Extracting x and y coordinates
            int x, y;
            sscanf(point.c_str(), "%d, %d", &x, &y);

            // Storing the values in the array
            if (count < maxPoints) {
                array[count][0] = x;
                array[count][1] = y;
                count++;
            }

            // Move to the next point
            start = line.find("(", end);
            end = line.find(")", start);
        }
    }

    // Close the file
    inputFile.close();
}
*/

/*
void cleanupMemory(int** array, int count) {
    for (int i = 0; i < count; ++i) {
        delete[] array[i];
    }
    delete[] array;
}*/