// welcome...
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <cmath>

#define cout std::cout
#define endl std::endl
#define string std::string
#define vector std::vector

string location;

/*void _sort(int arr[], int size);
void appendMatrix(int arr[], int size, int xloc, int _data[6][6]);
void displayMatrix(int _data[6][6], char _title[], bool toggleClear);
void copyData(int arr1[][2], int rawSize, int rawArr[][2]);
void setData(int _data[6][6], int target);
void closing();*/


// Fetch size of index
template <std::size_t Rows, std::size_t Cols>
int getIndex(int(&array)[Rows][Cols]){
    return Rows;
}

//----------------------------------------------------------------------------------------------

void inputFunc(string& _file1, string& _file2, string& _file3)      // Service prompt for user input data location
{
    string filePath;

    cout << "\nPlease enter reference folder location.\n\nEg : \"C:\\This PC\\EEE\\Reference\\Set 5\"";
    do {
        _file1 = "raw1.txt";
        _file2 = "raw2.txt";
        _file3 = "raw3.txt";
        cout << "\nFile location : ";
        std::getline(std::cin,filePath);
        bool local = (filePath!="LOCAL") && (filePath!="local") && (filePath!="Local");
        if(local){
            _file1 = filePath + "\\raw1.txt";
            _file2 = filePath + "\\raw2.txt";
            _file3 = filePath + "\\raw3.txt";
        }
        else{cout << "\nSearching local folder..." << endl;}
        
        std::ifstream input_file1(_file1);
        std::ifstream input_file2(_file2);
        std::ifstream input_file3(_file3);
        //to check either file location is valid or not
        if(input_file1.is_open()&&input_file2.is_open()&&input_file3.is_open()){
            location = filePath;
            break;
        }
        if(!input_file1.is_open()){
                cout << "   Missing raw1.txt!" << endl;
            }
        if(!input_file2.is_open()){
                cout << "   Missing raw2.txt!" << endl;
            }
        if(!input_file3.is_open()){
                cout << "   Missing raw3.txt!" << endl;
        }
        if(!local){
            std::cerr << "\nUnable to find data in local folder\nincomplete/missing data, try again.\n";
        }
        else{
            std::cerr << "\nUnable to find data in specified folder - '" << filePath << "'\nincomplete/missing data, try again.\n";
        }
        
    }
    while (true);
}

int countContiguousNumbers(const string& filename)                  // Counts number of coordinate data sets
{
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

void extractData(const string& fileName, int array[][2], int count, int maxPoints) // Extracts Raw data content to local variable
{
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

//----------------------------------------------------------------------------------------------

void copyData(int arr1[][2], int rawSize, int rawArr[][2])  // Copies data content from one array to another
{
    for(int i=0;i<rawSize;i++){
    for(int j=0;j<2;j++){
        arr1[i][j] = rawArr[i+1][j];             // skip copying (0, 0)
    }
}
}

void sortX(int size, int _data[][2])        // Bubble sort 2D Array
{
    for(int i=1;i<size;i++){
        for(int j=0;j<size-1;j++){
            if(_data[j+1][0]<_data[j][0]){
                int tempdata[2];
                tempdata[0]=_data[j][0];
                tempdata[1]=_data[j][1];

                _data[j][0]=_data[j+1][0];
                _data[j][1]=_data[j+1][1];
    
                _data[j+1][0]=tempdata[0];
                _data[j+1][1]=tempdata[1];
            }
        }
    }
}

void _sort(int arr[], int size)             // Bubble sort 1D Array
{
    for(int i=1;i<size;i++){
        for(int j=0;j<size-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void vectorSort(vector<int>& arr, int size)     // Bubble sort vector array
{
    for(int i = 1;i<size;i++) {
        for (int j=0;j<size-1;j++) {
            if (arr[j]>arr[j+1]) {
                std::swap(arr[j],arr[j+1]);
            }
        }
    }
}

void displayDataArray(int size, int _data[][2]) // Displays data from array
{
    if(size>0){
        for(int i=0;i<size;i++){
            for(int j=0;j<2;j++){
               cout << _data[i][j] << " ";
            }
            cout << "\n";
        }
    }
else{cout << "Empty data!" << endl;}
}

//----------------------------------------------------------------------------------------------

void appendMatrix(int arr[], int size, int xloc, int _data[6][6])   // Appends array data into matrix data
{      
// (input data, input data, input data, output data)
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

void vectorappendMatrix(const vector<int>& arr, int size, int xloc, int _data[6][6])    // Appends vector data into matrix data
{
    for (int i=0;i<size;i++) {
        if (arr[i] == 0) {
            cout << "EMPTY!!" << endl;
        } else {
            int indx = int((round(static_cast<double>(arr[i])/100.0)-1));
            if (indx>=0&&indx<6) { // Check if indx is within bounds
                _data[indx][xloc]++;
            } else {
                cout << "Index out of bounds: " << indx << endl;
            }
        }
    }
}

//----------------------------------------------------------------------------------------------

void displayMatrix(int _data[6][6], string _title, bool toggleClear)    // Displays data matrix
{
    cout << "------------- M a t r i x   d a t a   f o r   " << _title << " -------------------\n" << endl;
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

void setData(int _data[6][6], int target)       // Sets matrix data to discrete value
{
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(_data[i][j]!=0){
                _data[i][j]=target;
            }
        }
    }
}

void closing()    // Closing message
{
    cout << "\n---------------------------------------------------------------------------\n";
    cout << "\n";
    cout << "                       T h a n k   y o u" << endl;
    cout << "\n                 H a v e   a   g o o d   d a y   : ) \n" << endl;
    cout << "\n---------------------------------------------------------------------------\n";
}

//----------------------------------------------------------------------------------------------






/*
void writeDataToFile(const char* fileName, int _data[][6]) {
    // Open the file
    std::ofstream outputFile(fileName);

    // Check if the file is open
    if (!outputFile.is_open()) {
        std::cerr << "Error opening the file: " << fileName << endl;
        return;
    }
    outputFile << "Location of data: \n" << location << "\n" << endl;
    // Write the array contents to the file
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            outputFile << _data[i][j] << " ";
        }
        outputFile << endl;
    }

    // Close the file
    outputFile.close();
}
*/


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