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
#include <stdio.h>
#include <fstream>
#include <vector>
#include "functions.hpp"


#define cout std::cout
#define endl std::endl
#define string std::string
#define vector std::vector

//---------------------------------- V a r i a b l e s ---------------------------------
const int threshold = 30;
string file1 = "raw1.txt";
string file2 = "raw2.txt";
string file3 = "raw3.txt";

void converter(vector<vector<vector<int>>>vectorData, int dataIndex, int coordCounter[], int _data[][2], int _difference[], int title);
int data[6][6] = {{0, 0, 0, 0, 0, 0},
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

cout << "raw1 index: " << data1_Index << endl;
cout << "raw2 index: " << data2_Index << endl;
cout << "raw3 index: " << data3_Index << endl;

vector<vector<vector<int>>> dataSets(3, vector<vector<int>>(1, vector<int>(2)));
dataSets[0].resize(data1_Index);
dataSets[1].resize(data2_Index);
dataSets[2].resize(data3_Index);

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

for(int i=1;i<data1_Index;i++){
    for(int i=0;i<data1_Index-1;i++){
        if(data1[i+1][0]<data1[i][0]){
            int tempdata[2];
            tempdata[0]=data1[i][0];
            tempdata[1]=data1[i][1];

            data1[i][0]=data1[i+1][0];
            data1[i][1]=data1[i+1][1];
    
            data1[i+1][0]=tempdata[0];
            data1[i+1][1]=tempdata[1];
        }
    }
}

for(int i=1;i<data2_Index;i++){
    for(int i=0;i<data2_Index-1;i++){
        if(data2[i+1][0]<data2[i][0]){
            int tempdata[2];
            tempdata[0]=data2[i][0];
            tempdata[1]=data2[i][1];

            data2[i][0]=data2[i+1][0];
            data2[i][1]=data2[i+1][1];
    
            data2[i+1][0]=tempdata[0];
            data2[i+1][1]=tempdata[1];
        }
    }
}

for(int i=1;i<data3_Index;i++){
    for(int i=0;i<data3_Index-1;i++){
        if(data3[i+1][0]<data3[i][0]){
            int tempdata[2];
            tempdata[0]=data3[i][0];
            tempdata[1]=data3[i][1];

            data3[i][0]=data3[i+1][0];
            data3[i][1]=data3[i+1][1];
    
            data3[i+1][0]=tempdata[0];
            data3[i+1][1]=tempdata[1];
        }
    }
}
    
cout << "\n";
//-----------------------------------------------------------------------------------------------------------------------------------------------------






//------------------------------------ D i s p l a y   d a t a   a r r a y -------------------------------------------
cout << "\n>data1" << endl;
if(data1_Index>0){
    for(int i=0;i<data1_Index;i++){
        for(int j=0;j<2;j++){
            cout << data1[i][j] << " ";
        }
        cout << "\n";
    }
}
else{cout << "Empty data!" << endl;}

cout << "\n>data2" << endl;
if(data2_Index>0){
    for(int i=0;i<data2_Index;i++){
        for(int j=0;j<2;j++){
            cout << data2[i][j] << " ";
        }
        cout << "\n";
    }
}
else{cout << "Empty data!" << endl;}

cout << "\n>data3" << endl;
if(data3_Index>0){
    for(int i=0;i<data3_Index;i++){
        for(int j=0;j<2;j++){
            cout << data3[i][j] << " ";
        }
        cout << "\n";
    }
}
else{cout << "Empty data!" << endl;}

cout << "\n";
//-----------------------------------------------------------------------------------------------------------------------------------------------------






//----------------------- C e l l   e l e m e n t   c o u n t e r ---------------------------------------------------

vector<vector<vector<int>>> xcoord(3, vector<vector<int>>(6, vector<int>(0)));


int xcoord1[6] = {0, 0, 0, 0, 0, 0};                    // number of data exists across the x-axis for data1
int xcoord2[6] = {0, 0, 0, 0, 0, 0};                    // number of data exists across the x-axis for data2
int xcoord3[6] = {0, 0, 0, 0, 0, 0};                    // number of data exists across the x-axis for data3

//-----debugging variables----------
int x1Jump[5] = {0, 0, 0, 0, 0};                        // indexes where distinct data appears for data1
int x2Jump[5] = {0, 0, 0, 0, 0};                        // indexes where distinct data appears for data2        
int x3Jump[5] = {0, 0, 0, 0, 0};                        // indexes where distinct data appears for data3

int difference[3] = {1, 1, 1}; // number of distinct data, every data must have at least 1 distinct data, 1st index for raw1, 2nd index for raw2, 3rd index for raw3
//----------------------------------


converter(xcoord, data1_Index, xcoord1, data1, difference, 1);



cout << "---------------------- R E P O R T   2 ----------------------" << endl;
cout << "number of indexes found: " << data2_Index << endl;
if(data2_Index>0){                                          // not empty set
    for(int i=0;i<data2_Index;i++){
        int indx = int(round(static_cast<double>(data2[i][0])/100.0)-1);
        xcoord2[indx]++;
        xcoord[1][indx].resize(xcoord2[indx]);
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
        xcoord[2][indx].resize(xcoord3[indx]);
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

int start = 0;
for(int j=0;j<6;j++){
    for(int i=0;i<xcoord[0][j].size();i++){
        xcoord[0][j][i] = data1[i+start][1];
    }
    start += xcoord[0][j].size();
}

start = 0;
for(int j=0;j<6;j++){
    for(int i=0;i<xcoord[1][j].size();i++){
        xcoord[1][j][i] = data2[i+start][1];
    }
    start += xcoord[1][j].size();
}

start = 0;
for(int j=0;j<6;j++){
    for(int i=0;i<xcoord[2][j].size();i++){
        xcoord[2][j][i] = data3[i+start][1];
    }
    start += xcoord[2][j].size();
}


//----------------------------------------------------------------------------------------------------------------------------





//---------------------------------- s o r t   b y   y - c o o r d i n a t e   i n   a s c e n d i n g   o r d e r ---------------------------------

//vectorSort
for(int i=0;i<3;i++){
    for(int j=0;j<6;j++){
        for(int k=1;k<xcoord[i][j].size();k++){
            for(int l=0;l<xcoord[i][j].size()-k;l++){
                if(xcoord[i][j][l]>xcoord[i][j][l+1]){
                int temp = xcoord[i][j][l];
                xcoord[i][j][l] = xcoord[i][j][l+1];
                xcoord[i][j][l+1] = temp;
            }
            }
        }
    }
}

//vectorAppend
for(int i=0;i<3;i++){
    for(int j=0;j<6;j++){
        for(int k=0;k<xcoord[i][j].size();k++){
            int indx = int((round(static_cast<double>(xcoord[i][j][k])/100.0)-1));
            data[indx][j] = i+1;
        }
    }
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





/*/cout << "\n" << ydifference << " distinct y-coordinates found across x100A!" << endl;
cout << "\n";
for(int i=0;i<6;i++){               // dont care the unknown indexes, get every index+1, if index number later 0 is 0, ignore, maximum contain 6 distinct location
    cout << "jump index " << i+1 << " : " << x1Jump[i] << endl;
}*/
cout << "\n\n";



    writeDataToFile("output.txt", data);

    cout << "\nData has been written to output.txt" << endl;



cout << "\nData verification\n\n";

for(int k=0;k<3;k++){
    for(int i=0;i<6;i++){
        cout << "X" << i+1 << "00 > ";
        for(int j=0;j<xcoord[k][i].size();j++){
           cout << xcoord[k][i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

cout << "\n";

for(int i=0;i<6;i++){
    for(int j=0;j<6;j++){
        cout << data[i][j] << " ";
    }
    cout << "\n";
}

closing();






return 0;
}

void converter(vector<vector<vector<int>>>vectorData, int dataIndex, int coordCounter[], int _data[][2], int _difference[], int title){
cout << "---------------------- R E P O R T   " << title << " ----------------------" << endl;
cout << "number of indexes found: " << dataIndex << endl;
if(dataIndex>0){                                          // not empty set
    for(int i=0;i<dataIndex;i++){
        int indx = int(round(static_cast<double>(data[i][0])/100.0)-1);
        coordCounter[indx]++;
        vectorData[title-1][indx].resize(coordCounter[indx]);
        if(i!=dataIndex-1 && data[i+1][0]-_data[i][0]>threshold){            // distinct value
            _difference[title-1]++;
            cout << "found 1 difference! current difference: " << _difference[title-1] << ", current index: " << i << ", index jump: " << i+1 << endl;
            //x1Jump[_difference[0]-1] = i+1;
        }
    }

    cout << "\n{ " ;
    for(int i=0;i<6;i++){
    cout << coordCounter[i] << "\t";
    }cout << "}" << endl;
    cout << "\n" << _difference[title-1] << " distinct x-coordinates found!" << endl;

}
else{cout << "Empty data! No coordinates found!" << endl;}
cout << "-------------------------------------------------------------\n" << endl;

}