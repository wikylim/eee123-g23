/*  EEE123 COMPUTER PROGRAMMING MINI PROJECT | SEMESTER 1 | SESSION 23/24
    
    GROUP:      23
    TITLE:      Tabular Image Data to Matrix Data Converter (for OpenCV purposes)
    REVISION:   0

    MEMBERS DETAIL
    ROLES




    limitations of code:
    - using file contents with the format " raw1>> [{0, 0}, {0, 0}, {0, 0}, ... {0, 0}]", any changes of the format of the input files will result in error of code
    - works within the coordinates (x, y) = (100, 100) to (600, 600)

*/

#if __linux__                                           //DO NOT EDIT OR REMOVE
    #define CATCH_CONFIG_RUNNER                         //DO NOT EDIT OR REMOVE
    #include "catch.hpp"                                //DO NOT EDIT OR REMOVE
    int runCatchTests(int argc, char* const argv[]){    //DO NOT EDIT OR REMOVE
        return Catch::Session().run(argc, argv);}       //DO NOT EDIT OR REMOVE
#endif                                                  //DO NOT EDIT OR REMOVE

//#include <iomanip>
//#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include "functions.hpp"

#define cout std::cout
#define oout outputFile
#define endl std::endl
#define string std::string

//---------------------------------- V a r i a b l e s ---------------------------------
const int threshold = 30;
string file1 = "raw1.txt";
string file2 = "raw2.txt";
string file3 = "raw3.txt";
string outputTxt = "output.txt";

// for output
bool _toggleClear = 1;              // clean mode

int data[6][6] = {{0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  };

int dataA[6][6] = {{0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  };
int dataB[6][6] = {{0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  };
int dataC[6][6] = {{0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  };

//--------------------------------------------------------------------------------------

int main(int argc, char* const argv[]){                 //DO NOT EDIT OR REMOVE
    #if __linux__                                       //DO NOT EDIT OR REMOVE
        return runCatchTests(argc, argv);               //DO NOT EDIT OR REMOVE
    #endif                                              //DO NOT EDIT OR REMOVE

    // s t a r t   h e r e . . .

//----------------------------------------- f e t c h   r a w   d a t a   f i l e s -----------------------------------------------

    inputFunc(file1, file2, file3);

    do{
        string yn;
        cout << "\nClean Mode? [Y/N]] > ";
        std::getline(std::cin, yn);
        if(yn=="Y"||yn=="y"){
            _toggleClear = 1;
            cout << "\nClean mode: ON" << endl;
            break;
        }
        else if(yn=="N"||yn=="n"){
            _toggleClear = 0;
            cout << "\nClean mode: OFF" << endl;
            break;
        }
        else{
            cout << "\nNo input given, clean mode off (default)" << endl;
            break;
        }

    }

    while(true);

    int giveIndex;
    giveIndex = (countContiguousNumbers(file1)-1)/2;            // file contains raw1, it counts the number, so subtract the numbers of number read by 1, xy coordinates are fixed by 2, so divide by 2 to get the number of data sets, in this case, the array index size
    int data1_Index = giveIndex;
    //cout << "give Index 1 : " << giveIndex << endl;
    int raw1[giveIndex][2];
    int count1 = 0;
    // Extract data from raw1.txt
    extractData(file1, raw1, count1, giveIndex);

    giveIndex = (countContiguousNumbers(file2)-1)/2;
    int data2_Index = giveIndex;
    //cout << "give Index 2 : " << giveIndex << endl;
    int raw2[giveIndex][2];
    int count2 = 0;
    // Extract data from raw2.txt
    extractData(file2, raw2, count2, giveIndex);

    giveIndex = (countContiguousNumbers(file3)-1)/2;
    int data3_Index = giveIndex;
    //cout << "give Index 3 : " << giveIndex << endl;
    int raw3[giveIndex][2];
    int count3 = 0;    
    // Extract data from raw3.txt
    extractData(file3, raw3, count3, giveIndex);

//----------------------------------------------------------------------------------------------------------------------------------

//---------------------- P r o c e s s   &   a p p e n d   r a w   d a t a -------------------------------
//int data1_Index = sizeof(raw1) / sizeof(raw1[0]);              // manually get dimension1 index size
//int data2_Index = sizeof(raw2) / sizeof(raw2[0]);              // manually get dimension1 index size
//int data3_Index = sizeof(raw3) / sizeof(raw3[0]);              // manually get dimension1 index size

//int data1_Index = getIndex(raw1);
//int data2_Index = getIndex(raw2);
//int data3_Index = getIndex(raw3);

cout << "raw1 index: " << data1_Index << endl;
cout << "raw2 index: " << data2_Index << endl;
cout << "raw3 index: " << data3_Index << endl;

int data1[data1_Index][2];                                      // declaring data1
int data2[data2_Index][2];                                      // declaring data2
int data3[data3_Index][2];                                      // declaring data3

copyData(data1, data1_Index, raw1);
copyData(data2, data2_Index, raw2);
copyData(data3, data3_Index, raw3);

data1_Index--;                                                  // after removing (0, 0), decrease the size of array by 1
data2_Index--;                                                  // after removing (0, 0), decrease the size of array by 1
data3_Index--;                                                  // after removing (0, 0), decrease the size of array by 1

//-----------------------------------------------------------------------------------------------------------------------------------------------------






//---------------------------------- s o r t   b y   x - c o o r d i n a t e   i n   a s c e n d i n g   o r d e r ---------------------------------

sortX(data1_Index, data1);
sortX(data2_Index, data2);
sortX(data3_Index, data3);

cout << "\n";
//-----------------------------------------------------------------------------------------------------------------------------------------------------






//------------------------------------ D i s p l a y   d a t a   a r r a y -------------------------------------------
cout << "\n>data1" << endl;
displayDataArray(data1_Index, data1);

cout << "\n>data2" << endl;
displayDataArray(data2_Index, data2);

cout << "\n>data3" << endl;
displayDataArray(data3_Index, data3);

cout << "\n";
//-----------------------------------------------------------------------------------------------------------------------------------------------------






//----------------------- C e l l   e l e m e n t   c o u n t e r ---------------------------------------------------

int xcoord1[6] = {0, 0, 0, 0, 0, 0};                    // number of data exists across the x-axis for data1
int xcoord2[6] = {0, 0, 0, 0, 0, 0};                    // number of data exists across the x-axis for data2
int xcoord3[6] = {0, 0, 0, 0, 0, 0};                    // number of data exists across the x-axis for data3

//-----debugging variables----------
int x1Jump[5] = {0, 0, 0, 0, 0};                        // indexes where distinct data appears for data1
int x2Jump[5] = {0, 0, 0, 0, 0};                        // indexes where distinct data appears for data2        
int x3Jump[5] = {0, 0, 0, 0, 0};                        // indexes where distinct data appears for data3

int difference[3] = {1, 1, 1}; // number of distinct data, every data must have at least 1 distinct data, 1st index for raw1, 2nd index for raw2, 3rd index for raw3
//----------------------------------
cout << "---------------------- R E P O R T   1 ----------------------" << endl;
cout << "number of indexes found: " << data1_Index << endl;
if(data1_Index>0){                                          // not empty set
    for(int i=0;i<data1_Index;i++){
        int indx = int(round(static_cast<double>(data1[i][0])/100.0)-1);
        xcoord1[indx]++;
        if(i!=data1_Index-1 && data1[i+1][0]-data1[i][0]>threshold){            // distinct value
            difference[0]++;
            cout << "found 1 difference! current difference: " << difference[0] << ", current index: " << i << ", index jump: " << i+1 << endl;
            x1Jump[difference[0]-1] = i+1;
        }
    }
    cout << "\nJump Index > { " ;
    for(int i=0;i<6;i++){
    cout << x1Jump[i] << " ";
    }cout << "}" << endl;

    cout << "\n{ " ;
    for(int i=0;i<6;i++){
    cout << xcoord1[i] << "\t";
    }cout << "}" << endl;
    cout << "\n" << difference[0] << " distinct x-coordinates found!" << endl;

}
else{cout << "Empty data! No coordinates found!" << endl;}
cout << "-------------------------------------------------------------\n" << endl;

cout << "---------------------- R E P O R T   2 ----------------------" << endl;
cout << "number of indexes found: " << data2_Index << endl;
if(data2_Index>0){                                          // not empty set
    for(int i=0;i<data2_Index;i++){
        int indx = int(round(static_cast<double>(data2[i][0])/100.0)-1);
        xcoord2[indx]++;
        if(i!=data2_Index-1 && data2[i+1][0]-data2[i][0]>threshold){            // distinct value
            difference[1]++;
            cout << "found 1 difference! current difference: " << difference[1] << ", current index: " << i << ", index jump: " << i+1 << endl;
            x2Jump[difference[1]-1] = i+1;
        }
    }
    cout << "\nJump Index > { " ;
    for(int i=0;i<6;i++){
    cout << x2Jump[i] << " ";
    }cout << "}" << endl;

    cout << "\n{ " ;
    for(int i=0;i<6;i++){
    cout << xcoord2[i] << "\t";
    }cout << "}" << endl;
    cout << "\n" << difference[1] << " distinct x-coordinates found!" << endl;

}
else{cout << "Empty data! No coordinates found!" << endl;}
cout << "-------------------------------------------------------------\n" << endl;

cout << "---------------------- R E P O R T   3 ----------------------" << endl;
cout << "number of indexes found: " << data3_Index << endl;
if(data3_Index>0){                                          // not empty set
    for(int i=0;i<data3_Index;i++){
        int indx = int(round(static_cast<double>(data3[i][0])/100.0)-1);
        if(indx < 0){cout << "error!!!" << endl;}
        xcoord3[indx]++;
        if(i!=data3_Index-1 && data3[i+1][0]-data3[i][0]>threshold){            // distinct value
            difference[2]++;
            cout << "found 1 difference! current difference: " << difference[2] << ", current index: " << i << ", index jump: " << i+1 << endl;
            x3Jump[difference[2]-1] = i+1;
        }
    }
    cout << "\nJump Index > { " ;
    for(int i=0;i<6;i++){
    cout << x3Jump[i] << " ";
    }cout << "}" << endl;

    cout << "\n{ " ;
    for(int i=0;i<6;i++){
    cout << xcoord3[i] << "\t";
    }cout << "}" << endl;
    cout << "\n" << difference[2] << " distinct x-coordinates found!" << endl;

}
else{cout << "Empty data! No coordinates found!" << endl;}
cout << "-------------------------------------------------------------\n" << endl;
//-------------------------------------------------------------------------------------------------------------------




//------------------------------------------ append y-coordinates into each respective column ---------------------------------
int x100A[xcoord1[0]] = {0};
int x200A[xcoord1[1]] = {0};
int x300A[xcoord1[2]] = {0};
int x400A[xcoord1[3]] = {0};
int x500A[xcoord1[4]] = {0};
int x600A[xcoord1[5]] = {0};
if(data1_Index>0){
for(int i=0;i<xcoord1[0];i++){
    x100A[i]=data1[i][1];
}
for(int i=0;i<xcoord1[1];i++){
    x200A[i]=data1[i+xcoord1[0]][1];
}
for(int i=0;i<xcoord1[2];i++){
    x300A[i]=data1[i+xcoord1[0]+xcoord1[1]][1];
}
for(int i=0;i<xcoord1[3];i++){
    x400A[i]=data1[i+xcoord1[0]+xcoord1[1]+xcoord1[2]][1];
}
for(int i=0;i<xcoord1[4];i++){
    x500A[i]=data1[i+xcoord1[0]+xcoord1[1]+xcoord1[2]+xcoord1[3]][1];
}
for(int i=0;i<xcoord1[5];i++){
    x600A[i]=data1[i+xcoord1[0]+xcoord1[1]+xcoord1[2]+xcoord1[3]+xcoord1[4]][1];
}
}

int x100B[xcoord2[0]] = {0};
int x200B[xcoord2[1]] = {0};
int x300B[xcoord2[2]] = {0};
int x400B[xcoord2[3]] = {0};
int x500B[xcoord2[4]] = {0};
int x600B[xcoord2[5]] = {0};
if(data2_Index>0){
for(int i=0;i<xcoord2[0];i++){
    x100B[i]=data2[i][1];
}
for(int i=0;i<xcoord2[1];i++){
    x200B[i]=data2[i+xcoord2[0]][1];
}
for(int i=0;i<xcoord2[2];i++){
    x300B[i]=data2[i+xcoord2[0]+xcoord2[1]][1];
}
for(int i=0;i<xcoord2[3];i++){
    x400B[i]=data2[i+xcoord2[0]+xcoord2[1]+xcoord2[2]][1];
}
for(int i=0;i<xcoord2[4];i++){
    x500B[i]=data2[i+xcoord2[0]+xcoord2[1]+xcoord2[2]+xcoord2[3]][1];
}
for(int i=0;i<xcoord2[5];i++){
    x600B[i]=data2[i+xcoord2[0]+xcoord2[1]+xcoord2[2]+xcoord2[3]+xcoord2[4]][1];
}
}

int x100C[xcoord3[0]] = {0};
int x200C[xcoord3[1]] = {0};
int x300C[xcoord3[2]] = {0};
int x400C[xcoord3[3]] = {0};
int x500C[xcoord3[4]] = {0};
int x600C[xcoord3[5]] = {0};
if(data3_Index>0){
for(int i=0;i<xcoord3[0];i++){
    x100C[i]=data3[i][1];
}
for(int i=0;i<xcoord3[1];i++){
    x200C[i]=data3[i+xcoord3[0]][1];
}
for(int i=0;i<xcoord3[2];i++){
    x300C[i]=data3[i+xcoord3[0]+xcoord3[1]][1];
}
for(int i=0;i<xcoord3[3];i++){
    x400C[i]=data3[i+xcoord3[0]+xcoord3[1]+xcoord3[2]][1];
}
for(int i=0;i<xcoord3[4];i++){
    x500C[i]=data3[i+xcoord3[0]+xcoord3[1]+xcoord3[2]+xcoord3[3]][1];
}
for(int i=0;i<xcoord3[5];i++){
    x600C[i]=data3[i+xcoord3[0]+xcoord3[1]+xcoord3[2]+xcoord3[3]+xcoord3[4]][1];
}
}

//----------------------------------------------------------------------------------------------------------------------------





//---------------------------------- s o r t   b y   y - c o o r d i n a t e   i n   a s c e n d i n g   o r d e r ---------------------------------
if(data1_Index>0){
    _sort(x100A, xcoord1[0]);
    _sort(x200A, xcoord1[1]);
    _sort(x300A, xcoord1[2]);
    _sort(x400A, xcoord1[3]);
    _sort(x500A, xcoord1[4]);
    _sort(x600A, xcoord1[5]);
    appendMatrix(x100A, xcoord1[0], 0, dataA);
    appendMatrix(x200A, xcoord1[1], 1, dataA);
    appendMatrix(x300A, xcoord1[2], 2, dataA);
    appendMatrix(x400A, xcoord1[3], 3, dataA);
    appendMatrix(x500A, xcoord1[4], 4, dataA);
    appendMatrix(x600A, xcoord1[5], 5, dataA);
}
if(data2_Index>0){
    _sort(x100B, xcoord2[0]);
    _sort(x200B, xcoord2[1]);
    _sort(x300B, xcoord2[2]);
    _sort(x400B, xcoord2[3]);
    _sort(x500B, xcoord2[4]);
    _sort(x600B, xcoord2[5]);
    appendMatrix(x100B, xcoord2[0], 0, dataB);
    appendMatrix(x200B, xcoord2[1], 1, dataB);
    appendMatrix(x300B, xcoord2[2], 2, dataB);
    appendMatrix(x400B, xcoord2[3], 3, dataB);
    appendMatrix(x500B, xcoord2[4], 4, dataB);
    appendMatrix(x600B, xcoord2[5], 5, dataB);
}
if(data3_Index>0){
    _sort(x100C, xcoord3[0]);
    _sort(x200C, xcoord3[1]);
    _sort(x300C, xcoord3[2]);
    _sort(x400C, xcoord3[3]);
    _sort(x500C, xcoord3[4]);
    _sort(x600C, xcoord3[5]);
    appendMatrix(x100C, xcoord3[0], 0, dataC);
    appendMatrix(x200C, xcoord3[1], 1, dataC);
    appendMatrix(x300C, xcoord3[2], 2, dataC);
    appendMatrix(x400C, xcoord3[3], 3, dataC);
    appendMatrix(x500C, xcoord3[4], 4, dataC);
    appendMatrix(x600C, xcoord3[5], 5, dataC);
}

//--------------------------------------------------------------------------------------------------------------------------------------------------





//----------------------------------- D i s p l a y   a p p e n d e d   y - c o o r d i n a t e s --------------------------------------------
cout << "\n-----------------------------------------------------------------" << endl;
cout << "  DISPLAYING LIST OF Y-COORDINATES FOR EACH RESPECTIVE X-AXIS " << endl;
cout << "-----------------------------------------------------------------";

//cout << x100A[0] << endl;
cout << "\ndata1 y-coord: ";
cout << "\nx100A: ";
for(int i=0;i<xcoord1[0];i++){              // get xcoord y-coordinate for data1
    cout << x100A[i] << " ";                 // x location = 100
}
cout << "\nx200A: ";
for(int i=0;i<xcoord1[1];i++){
    cout << x200A[i] << " ";
}
cout << "\nx300A: ";
for(int i=0;i<xcoord1[2];i++){
    cout << x300A[i] << " ";
}
cout << "\nx400A: ";
for(int i=0;i<xcoord1[3];i++){
    cout << x400A[i] << " ";
}
cout << "\nx500A: ";
for(int i=0;i<xcoord1[4];i++){
    cout << x500A[i] << " ";
}
cout << "\nx600A: ";
for(int i=0;i<xcoord1[5];i++){
    cout << x600A[i] << " ";
}

cout << "\n\ndata2 y-coord: ";
cout << "\nx100B: ";
for(int i=0;i<xcoord2[0];i++){              // get xcoord y-coordinate for data2
    cout << x100B[i] << " ";                 // x location = 100
}
cout << "\nx200B: ";
for(int i=0;i<xcoord2[1];i++){
    cout << x200B[i] << " ";
}
cout << "\nx300B: ";
for(int i=0;i<xcoord2[2];i++){
    cout << x300B[i] << " ";
}
cout << "\nx400B: ";
for(int i=0;i<xcoord2[3];i++){
    cout << x400B[i] << " ";
}
cout << "\nx500B: ";
for(int i=0;i<xcoord2[4];i++){
    cout << x500B[i] << " ";
}
cout << "\nx600B: ";
for(int i=0;i<xcoord2[5];i++){
    cout << x600B[i] << " ";
}

cout << "\n\ndata3 y-coord: ";
cout << "\nx100C: ";
for(int i=0;i<xcoord3[0];i++){              // get xcoord y-coordinate for data3
    cout << x100C[i] << " ";                 // x location = 100
}
cout << "\nx200C: ";
for(int i=0;i<xcoord3[1];i++){
    cout << x200C[i] << " ";
}
cout << "\nx300C: ";
for(int i=0;i<xcoord3[2];i++){
    cout << x300C[i] << " ";
}
cout << "\nx400C: ";
for(int i=0;i<xcoord3[3];i++){
    cout << x400C[i] << " ";
}
cout << "\nx500C: ";
for(int i=0;i<xcoord3[4];i++){
    cout << x500C[i] << " ";
}
cout << "\nx600C: ";
for(int i=0;i<xcoord3[5];i++){
    cout << x600C[i] << " ";
}
//------------------------------------------------------------------------------------------------------------------

//------------------------------ D i s p l a y   m a t r i x   d a t a   i n    t e r m i n a l ----------------------------------
cout << "\n\n";
displayMatrix(dataA, "R a w   1", 1);
displayMatrix(dataB, "R a w   2", 1);
displayMatrix(dataC, "R a w   3", 1);

setData(dataA, 1);                      // set data1 data into 1
setData(dataB, 2);                      // set data2 data into 2
setData(dataC, 3);                      // set data3 data into 3

// Add dataA, dataB, dataC into Matrix
for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            data[i][j] += dataA[i][j];
            data[i][j] += dataB[i][j];
            data[i][j] += dataC[i][j];
        }
    }

displayMatrix(data, "F i n a l", 1);

//------------------------------------ O u t p u t   f i l e   r e p o r t   g e n e r a t o r -------------------------------------
    std::ofstream outputFile(outputTxt);
    std::ifstream sourceFile1(file1);
    std::ifstream sourceFile2(file2);
    std::ifstream sourceFile3(file3);
    outputFile << "Location of data: \n" << location << "\n" << endl;
    // Write the array contents to the file
    
    // Display raw data fed
    string _line;
    oout << "Input ";
    while(std::getline(sourceFile1, _line)) {
        oout << _line << endl;
    }
    oout << "Input ";
    while(std::getline(sourceFile2, _line)) {
        oout << _line << endl;
    }
    oout << "Input ";
    while(std::getline(sourceFile3, _line)) {
        oout << _line << endl;
    }
    oout << "\n\n";
    sourceFile1.close();
    sourceFile2.close();
    sourceFile3.close();
    
    // Display raw data indices
    oout << "raw1 Index: " << data1_Index << endl;
    oout << "raw2 Index: " << data2_Index << endl;
    oout << "raw3 Index: " << data3_Index << endl;
    oout << "\n\n";

    // Display copied and sorted data (sort by x-coordinate)
    oout << ">data1 (sorted by x-axis ascending order)" << endl;
    if(data1_Index>0){
        for(int i=0;i<data1_Index;i++){
            for(int j=0;j<2;j++){
               oout << data1[i][j] << " ";
            }
            oout << " | "; //"\n";
        }
    }
    else{oout << "Empty data!" << endl;}
    oout << "\n\n";
    oout << ">data2 (sorted by x-axis ascending order)" << endl;
    if(data2_Index>0){
        for(int i=0;i<data2_Index;i++){
            for(int j=0;j<2;j++){
               oout << data2[i][j] << " ";
            }
            oout << " | "; //"\n";
        }
    }
    else{oout << "Empty data!" << endl;}
    oout << "\n\n";
    oout << ">data3 (sorted by x-axis ascending order)" << endl;
    if(data3_Index>0){
        for(int i=0;i<data3_Index;i++){
            for(int j=0;j<2;j++){
               oout << data3[i][j] << " ";
            }
            oout << " | "; //"\n";
        }
    }
    else{oout << "Empty data!" << endl;}
    oout << "\n\n";

    // Display preliminary report
    oout << "-----------------------------------------------------------------" << endl;
    oout << "--------- P R E L I M I N A R Y     R E P O R T -----------------" << endl;
    if(data1_Index>0){
    oout << "---------------------- R E P O R T   1 --------------------------" << endl;
    oout << "number of indexes found: " << data1_Index << endl;
    oout << "[\t";
    for(int i=0;i<6;i++){
    oout << xcoord1[i] << "\t";
    }oout << "]" << endl;
    oout << " " << difference[0] << " distinct x-coordinates found!" << endl;
    }
    else{oout << "Empty data! No coordinates found!" << endl;}
    oout << "-----------------------------------------------------------------\n" << endl;

    if(data2_Index>0){
    oout << "---------------------- R E P O R T   2 ----------------------" << endl;
    oout << "number of indexes found: " << data2_Index << endl;
    oout << "[\t";
    for(int i=0;i<6;i++){
    oout << xcoord2[i] << "\t";
    }oout << "]" << endl;
    oout << " " << difference[1] << " distinct x-coordinates found!" << endl;
    }
    else{oout << "Empty data! No coordinates found!" << endl;}
    oout << "-----------------------------------------------------------------\n" << endl;

    if(data3_Index>0){
    oout << "---------------------- R E P O R T   3 ----------------------" << endl;
    oout << "number of indexes found: " << data3_Index << endl;
    oout << "[\t";
    for(int i=0;i<6;i++){
    oout << xcoord3[i] << "\t";
    }oout << "]" << endl;
    oout << " " << difference[2] << " distinct x-coordinates found!" << endl;
    }
    else{oout << "Empty data! No coordinates found!" << endl;}
    oout << "-----------------------------------------------------------------\n" << endl;

    // Displaying y-coordinates
    oout << "\n-----------------------------------------------------------------" << endl;
    oout << "  DISPLAYING LIST OF Y-COORDINATES FOR EACH RESPECTIVE X-AXIS " << endl;
    oout << "-----------------------------------------------------------------";
    oout << "\ndata1 y-coord: ";
    oout << "\nx100A: ";
    for(int i=0;i<xcoord1[0];i++){              // get xcoord y-coordinate for data1
        oout << x100A[i] << " ";                 // x location = 100
    }
    oout << "\nx200A: ";
    for(int i=0;i<xcoord1[1];i++){
    oout << x200A[i] << " ";
    }
    oout << "\nx300A: ";
    for(int i=0;i<xcoord1[2];i++){
        oout << x300A[i] << " ";
    }
    oout << "\nx400A: ";
    for(int i=0;i<xcoord1[3];i++){
        oout << x400A[i] << " ";
    }
    oout << "\nx500A: ";
    for(int i=0;i<xcoord1[4];i++){
        oout << x500A[i] << " ";
    }
    oout << "\nx600A: ";
    for(int i=0;i<xcoord1[5];i++){
        oout << x600A[i] << " ";
    }

    oout << "\n\ndata2 y-coord: ";
    oout << "\nx100B: ";
    for(int i=0;i<xcoord2[0];i++){              // get xcoord y-coordinate for data2
        oout << x100B[i] << " ";                 // x location = 100
    }
    oout << "\nx200B: ";
    for(int i=0;i<xcoord2[1];i++){
        oout << x200B[i] << " ";
    }
    oout << "\nx300B: ";
    for(int i=0;i<xcoord2[2];i++){
    oout << x300B[i] << " ";
    }
    oout << "\nx400B: ";
    for(int i=0;i<xcoord2[3];i++){
        oout << x400B[i] << " ";
    }
    oout << "\nx500B: ";
    for(int i=0;i<xcoord2[4];i++){
        oout << x500B[i] << " ";
    }
    oout << "\nx600B: ";
    for(int i=0;i<xcoord2[5];i++){
        oout << x600B[i] << " ";
    }

    oout << "\n\ndata3 y-coord: ";
    oout << "\nx100C: ";
    for(int i=0;i<xcoord3[0];i++){              // get xcoord y-coordinate for data3
        oout << x100C[i] << " ";                 // x location = 100
    }
    oout << "\nx200C: ";
    for(int i=0;i<xcoord3[1];i++){
        oout << x200C[i] << " ";
    }
    oout << "\nx300C: ";
    for(int i=0;i<xcoord3[2];i++){
        oout << x300C[i] << " ";
    }
    oout << "\nx400C: ";
    for(int i=0;i<xcoord3[3];i++){
        oout << x400C[i] << " ";
    }
    oout << "\nx500C: ";
    for(int i=0;i<xcoord3[4];i++){
        oout << x500C[i] << " ";
    }
    oout << "\nx600C: ";
    for(int i=0;i<xcoord3[5];i++){
        oout << x600C[i] << " ";
    }
    oout << "\n-----------------------------------------------------------------" << endl;
    oout << "\n\n";

    // Display for Matrix form
    oout << "------------------ M a t r i x   D i s p l a y ------------------" << endl;
    oout << "Clean mode: ";
    if(_toggleClear){oout << "ON";}else{oout << "OFF";}oout << "\n\n";
    oout << "------- M a t r i x   d a t a   f o r   d a t a   1 -------------\n";
    oout << "___________________________________________________" << endl;
    oout << "\tR1\tR2\tR3\tR4\tR5\tNS" << endl;
    for(int j=0;j<6;j++){
        if(j<4){
            oout << "D\t";
        }
        else{oout << "R\t";}
        for(int i=0;i<6;i++){
            if(dataA[j][i]==0 && _toggleClear){oout << "\t";}
            else{oout << dataA[j][i] << "\t";}
        }
        oout << "\n";
    }   oout << "_________________________________________________________________" << endl;
    //oout << "\n-----------------------------------------------------------------------------\n";

    oout << "------- M a t r i x   d a t a   f o r   d a t a   2 -------------\n";
    oout << "___________________________________________________" << endl;
    oout << "\tR1\tR2\tR3\tR4\tR5\tNS" << endl;
    for(int j=0;j<6;j++){
        if(j<4){
            oout << "D\t";
        }
        else{oout << "R\t";}
        for(int i=0;i<6;i++){
            if(dataB[j][i]==0 && _toggleClear){oout << "\t";}
            else{oout << dataB[j][i] << "\t";}
        }
        oout << "\n";
    }   oout << "_________________________________________________________________" << endl;
    //oout << "\n-----------------------------------------------------------------------------\n";

    oout << "------- M a t r i x   d a t a   f o r   d a t a   3 -------------\n";
    oout << "___________________________________________________" << endl;
    oout << "\tR1\tR2\tR3\tR4\tR5\tNS" << endl;
    for(int j=0;j<6;j++){
        if(j<4){
            oout << "D\t";
        }
        else{oout << "R\t";}
        for(int i=0;i<6;i++){
            if(dataC[j][i]==0 && _toggleClear){oout << "\t";}
            else{oout << dataC[j][i] << "\t";}
        }
        oout << "\n";
    }   oout << "_________________________________________________________________" << endl;
    //oout << "\n-----------------------------------------------------------------------------\n";

    oout << "----------------- F i n a l   M a t r i x -----------------------\n";
    oout << "___________________________________________________" << endl;
    oout << "\tR1\tR2\tR3\tR4\tR5\tNS" << endl;
    for(int j=0;j<6;j++){
        if(j<4){
            oout << "D\t";
        }
        else{oout << "R\t";}
        for(int i=0;i<6;i++){
            if(data[j][i]==0 && _toggleClear){oout << "\t";}
            else{oout << data[j][i] << "\t";}
        }
        oout << "\n";
    }   oout << "_________________________________________________________________" << endl;
    //oout << "\n-----------------------------------------------------------------------------\n";
    oout << "\n";

    // bye
    oout << "\t\tE N D   O F   R E P O R T" << endl;
    oout << "\n-----------------------------------------------------------------\n";
    oout << "\n";
    oout << "                   T h a n k   y o u" << endl;
    oout << "\n             H a v e   a   g o o d   d a y   : ) \n" << endl;
    oout << "\n-----------------------------------------------------------------\n";
    

    /*/ quick display
    oout << "\n\n\n\n\n";
    oout << "---------------\nvanilla mode (debugging)\n---------------\n";
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            outputFile << data[i][j] << " ";
        }
        outputFile << endl;
    }

    oout << "\n\nVector data\n";
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            outputFile << dataV[i][j] << " ";
        }
        outputFile << endl;
    }*/

    // Close the file
    outputFile.close();
    
    cout << "\nData has been written to output.txt\nReport generated" << endl;
   
    closing();

return 0;

}


