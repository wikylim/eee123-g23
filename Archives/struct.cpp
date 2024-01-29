/*  EEE123 COMPUTER PROGRAMMING MINI PROJECT | SEMESTER 1 | SESSION 23/24
    
    GROUP:      23
    TITLE:      Tabular Image Data to Matrix Data Converter (for OpenCV purposes)
    VERSION:    (4) Vectorstruct
    REVISION:   4.52

    MEMBERS DETAIL                          MATRIC          ROLES       EMAIL                                   CONTACT
    1	LIM WIKY	                        22305415	    1, 2, 6	    wikylim@student.usm.my	                018 262 4913
    2	LIM XING	                        22301447	    5	        limxing30@student.usm.my	            017-4545260
    3	MOHAMAD AYDIN BIN MOHD GHAZALI	    22300017	    2,3	        aydin.ghaz@student.usm.my	
    4	AEESHA ERINA BINTI DAUD	            22301711	    5	        aeeshaerina@student.usm.my	            010-6688767
    5	EDWARD EE JIN HAO 	                22301440	    3, 4	    edwardeejinhao@student.usm.my	        012-4447831
    6	LEE WEI XIAN	                    22302757	    4	        leeweixian5561@student.usm.my	        017-4252634
    
    ROLES                                   TYPE            DESCRIPTION
    1   Problem & solution seeker	        Overlooker	    Generate problem statement, propose method flow, prepare preliminary data				
    2   [Section 1] Input data	            Algorithm	    Propose solution and write code for inputting/sourcing data from .txt file data sets				
    3   [Section 2] Sorter	                Algorithm	    Propose solution and write code for sorting the (x, y) coordinate in array 				
    4   [Section 3] Converter	            Algorithm	    Propose solution and write code for converting sorted data into matrix form				
    5   [Section 4] Output	                Algorithm	    Propose solution and write code for displaying raw data, processed data and final data in terminal (final data in matrix form), output .txt file				
    6   Juice mixer	                        Algorithm	    Adjust, fix and combine all the codes (Section 1 to 4) into one main code				
    7   [Section 5] OpenCV (optional)	    Algorithm	    Write code for openCV template matching				
    8   Tester	                            Tester	        Code inspection, test and validate code functionality				



    limitations of code:
    - using file contents with the format " raw1>> [{0, 0}, {0, 0}, {0, 0}, ... {0, 0}]", any changes of the format of the input files will result in error of code
    - works within the coordinates (x, y) = (100, 100) to (600, 600)
    - size of data index must be according to raw data and accurate

*/

#if __linux__                                           //DO NOT EDIT OR REMOVE
    #define CATCH_CONFIG_RUNNER                         //DO NOT EDIT OR REMOVE
    #include "catch.hpp"                                //DO NOT EDIT OR REMOVE
    int runCatchTests(int argc, char* const argv[]){    //DO NOT EDIT OR REMOVE
        return Catch::Session().run(argc, argv);}       //DO NOT EDIT OR REMOVE
#endif                                                  //DO NOT EDIT OR REMOVE

#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "functions.hpp"

#include <vector>

#define cout std::cout
#define oout outputFile
#define endl std::endl
#define string std::string
#define vector std::vector

//---------------------------------- V a r i a b l e s ---------------------------------
const int threshold = 30;
string file1 = "raw1.txt";
string file2 = "raw2.txt";
string file3 = "raw3.txt";
string outputTxt = "output_v4.txt";

// for output
bool _toggleClear = 1;              // clean mode

int data[6][6] = {{0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  };


struct data {
    int type;
    int dataIndex;
    
    int xcoord[6] = {0, 0, 0, 0, 0, 0};
    int xJump[5] = {0, 0, 0, 0, 0};             // for debugging purpose
    int difference = 0;                         // for debugging purpose

    int mdata[6][6] = { {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        };

    void displayIndex(){
        cout << "raw" << type << " index: " << dataIndex << endl;
    }

}data1, data2, data3;


//--------------------------------------------------------------------------------------

int main(int argc, char* const argv[]){                 //DO NOT EDIT OR REMOVE
    #if __linux__                                       //DO NOT EDIT OR REMOVE
        return runCatchTests(argc, argv);               //DO NOT EDIT OR REMOVE
    #endif                                              //DO NOT EDIT OR REMOVE

    // s t a r t   h e r e . . .


    data1.type = 1;
    data2.type = 2;
    data3.type = 3;


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

    data1.dataIndex = (countContiguousNumbers(file1)-1)/2;
    int raw1[data1.dataIndex][2];
    // Extract data from raw1.txt
    extractData(file1, raw1, 0, data1.dataIndex);

    data2.dataIndex = (countContiguousNumbers(file2)-1)/2;
    int raw2[data2.dataIndex][2];
    // Extract data from raw2.txt
    extractData(file2, raw2, 0, data2.dataIndex);

    data3.dataIndex = (countContiguousNumbers(file3)-1)/2;
    int raw3[data3.dataIndex][2];  
    // Extract data from raw3.txt
    extractData(file3, raw3, 0, data3.dataIndex);
//-----------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------- P r o c e s s   &   a p p e n d   r a w   d a t a -------------------------------

data1.displayIndex();
int dataV1[data1.dataIndex][2];                                      // declaring data1
copyData(dataV1, data1.dataIndex, raw1);
data1.dataIndex--;                                                  // after removing (0, 0), decrease the size of array by 1

data2.displayIndex();
int dataV2[data2.dataIndex][2];                                      // declaring data2
copyData(dataV2, data2.dataIndex, raw2);
data2.dataIndex--;                                                  // after removing (0, 0), decrease the size of array by 1


data3.displayIndex();
int dataV3[data3.dataIndex][2];                                      // declaring data3
copyData(dataV3, data3.dataIndex, raw3);
data3.dataIndex--;                                                  // after removing (0, 0), decrease the size of array by 1

//-----------------------------------------------------------------------------------------------------------------------------------------------------





//---------------------------------- s o r t   b y   x - c o o r d i n a t e   i n   a s c e n d i n g   o r d e r ---------------------------------

sortX(data1.dataIndex, dataV1);
sortX(data2.dataIndex, dataV2);
sortX(data3.dataIndex, dataV3);

cout << "\n";
//-----------------------------------------------------------------------------------------------------------------------------------------------------





//------------------------------------ D i s p l a y   d a t a   a r r a y -------------------------------------------
cout << "\n>data1" << endl;
displayDataArray(data1.dataIndex, dataV1);

cout << "\n>data2" << endl;
displayDataArray(data2.dataIndex, dataV2);

cout << "\n>data3" << endl;
displayDataArray(data3.dataIndex, dataV3);

cout << "\n";
//-----------------------------------------------------------------------------------------------------------------------------------------------------





//----------------------- C e l l   e l e m e n t   c o u n t e r ---------------------------------------------------

cout << "---------------------- R E P O R T   1 ----------------------" << endl;
cout << "number of indexes found: " << data1.dataIndex << endl;
if(data1.dataIndex>0){                                          // not empty set
    for(int i=0;i<data1.dataIndex;i++){
        int indx = int(round(static_cast<double>(dataV1[i][0])/100.0)-1);
        data1.xcoord[indx]++;
        if(i!=data1.dataIndex-1 && dataV1[i+1][0]-dataV1[i][0]>threshold){            // distinct value
            data1.difference++;
            cout << "found 1 difference! current difference: " << data1.difference << ", current index: " << i << ", index jump: " << i+1 << endl;
            data1.xJump[data1.difference-1] = i+1;
        }
    }
    cout << "\nJump Index > { " ;
    for(int i=0;i<6;i++){
    cout << data1.xJump[i] << " ";
    }cout << "}" << endl;

    cout << "\n{ " ;
    for(int i=0;i<6;i++){
    cout << data1.xcoord[i] << "\t";
    }cout << "}" << endl;
    cout << "\n" << data1.difference << " distinct x-coordinates found!" << endl;

}
else{cout << "Empty data! No coordinates found!" << endl;}
cout << "-------------------------------------------------------------\n" << endl;

cout << "---------------------- R E P O R T   2 ----------------------" << endl;
cout << "number of indexes found: " << data2.dataIndex << endl;
if(data2.dataIndex>0){                                          // not empty set
    for(int i=0;i<data2.dataIndex;i++){
        int indx = int(round(static_cast<double>(dataV2[i][0])/100.0)-1);
        data2.xcoord[indx]++;
        if(i!=data2.dataIndex-1 && dataV2[i+1][0]-dataV2[i][0]>threshold){            // distinct value
            data2.difference++;
            cout << "found 1 difference! current difference: " << data2.difference << ", current index: " << i << ", index jump: " << i+1 << endl;
            data2.xJump[data2.difference-1] = i+1;
        }
    }
    cout << "\nJump Index > { " ;
    for(int i=0;i<6;i++){
    cout << data2.xJump[i] << " ";
    }cout << "}" << endl;

    cout << "\n{ " ;
    for(int i=0;i<6;i++){
    cout << data2.xcoord[i] << "\t";
    }cout << "}" << endl;
    cout << "\n" << data2.difference << " distinct x-coordinates found!" << endl;

}
else{cout << "Empty data! No coordinates found!" << endl;}
cout << "-------------------------------------------------------------\n" << endl;

cout << "---------------------- R E P O R T   3 ----------------------" << endl;
cout << "number of indexes found: " << data3.dataIndex << endl;
if(data3.dataIndex>0){                                          // not empty set
    for(int i=0;i<data3.dataIndex;i++){
        int indx = int(round(static_cast<double>(dataV3[i][0])/100.0)-1);
        if(indx < 0){cout << "error!!!" << endl;}
        data3.xcoord[indx]++;
        if(i!=data3.dataIndex-1 && dataV3[i+1][0]-dataV3[i][0]>threshold){            // distinct value
            data3.difference++;
            cout << "found 1 difference! current difference: " << data3.difference << ", current index: " << i << ", index jump: " << i+1 << endl;
            data3.xJump[data3.difference-1] = i+1;
        }
    }
    cout << "\nJump Index > { " ;
    for(int i=0;i<6;i++){
    cout << data3.xJump[i] << " ";
    }cout << "}" << endl;

    cout << "\n{ " ;
    for(int i=0;i<6;i++){
    cout << data3.xcoord[i] << "\t";
    }cout << "}" << endl;
    cout << "\n" << data3.difference << " distinct x-coordinates found!" << endl;

}
else{cout << "Empty data! No coordinates found!" << endl;}
cout << "-------------------------------------------------------------\n" << endl;
//-----------------------------------------------------------------------------------------------------------------------------------------------------





//------------------------------------------ append y-coordinates into each respective column ---------------------------------
vector<vector<vector<int>>> xcoord(3, vector<vector<int>>(6, vector<int>(1)));
int cumulativeIndex = 0;

for(int i=0;i<6;i++){
    xcoord[0][i].resize(data1.xcoord[i]);
    for(int j=0;j<data1.xcoord[i];j++){
        xcoord[0][i][j]=dataV1[j+cumulativeIndex][1];
    }
    cumulativeIndex += data1.xcoord[i];
}

cumulativeIndex = 0;
for(int i=0;i<6;i++){
    xcoord[1][i].resize(data2.xcoord[i]);
    for(int j=0;j<data2.xcoord[i];j++){
        xcoord[1][i][j]=dataV2[j+cumulativeIndex][1];
    }
    cumulativeIndex += data2.xcoord[i];
}

cumulativeIndex = 0;
for(int i=0;i<6;i++){
    xcoord[2][i].resize(data3.xcoord[i]);
    for(int j=0;j<data3.xcoord[i];j++){
        xcoord[2][i][j]=dataV3[j+cumulativeIndex][1];
    }
    cumulativeIndex += data3.xcoord[i];
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------





//---------------------------------- s o r t   b y   y - c o o r d i n a t e   i n   a s c e n d i n g   o r d e r ---------------------------------
if(data1.dataIndex>0){
    for(int i=0;i<6;i++){   
        vectorSort(xcoord[0][i], data1.xcoord[i]);
        vectorappendMatrix(xcoord[0][i], data1.xcoord[i], i, data1.mdata);
    }  
}
if(data2.dataIndex>0){
    for(int i=0;i<6;i++){   
        vectorSort(xcoord[1][i], data2.xcoord[i]);
        vectorappendMatrix(xcoord[1][i], data2.xcoord[i], i, data2.mdata);
    }    
}
if(data3.dataIndex>0){
    for(int i=0;i<6;i++){   
        vectorSort(xcoord[2][i], data3.xcoord[i]);
        vectorappendMatrix(xcoord[2][i], data3.xcoord[i], i, data3.mdata);
    } 
}

//--------------------------------------------------------------------------------------------------------------------------------------------------





//----------------------------------- D i s p l a y   a p p e n d e d   y - c o o r d i n a t e s --------------------------------------------
cout << "\n-----------------------------------------------------------------" << endl;
cout << "  DISPLAYING LIST OF Y-COORDINATES FOR EACH RESPECTIVE X-AXIS " << endl;
cout << "-----------------------------------------------------------------";

cout << "\ndata1 y-coord: ";
for(int i=0;i<6;i++){
    cout << "\nx"<< i+1 << "00A: ";
    for(int j=0;j<data1.xcoord[i];j++){                 // get xcoord y-coordinate for data1
        cout << xcoord[0][i][j] << " ";                 // x location = 100
    }
}

cout << "\ndata2 y-coord: ";
for(int i=0;i<6;i++){
    cout << "\nx"<< i+1 << "00B: ";
    for(int j=0;j<data2.xcoord[i];j++){                 // get xcoord y-coordinate for data2
        cout << xcoord[1][i][j] << " ";                 // x location = 100
    }
}

cout << "\ndata3 y-coord: ";
for(int i=0;i<6;i++){
    cout << "\nx"<< i+1 << "00C: ";
    for(int j=0;j<data3.xcoord[i];j++){                 // get xcoord y-coordinate for data2
        cout << xcoord[2][i][j] << " ";                 // x location = 100
    }
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

//------------------------------ D i s p l a y   m a t r i x   d a t a   i n    t e r m i n a l ----------------------------------------------------
cout << "\n\n";

displayMatrix(data1.mdata, "R a w   1", 1);
setData(data1.mdata, 1);                      // set data1 data into 1

displayMatrix(data2.mdata, "R a w   2", 1);
setData(data2.mdata, 2);                      // set data2 data into 2

displayMatrix(data3.mdata, "R a w   3", 1);
setData(data3.mdata, 3);                      // set data3 data into 3

// Add data1.mdata, data2.mdata, data3.mdata into Matrix
for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            data[i][j] += data1.mdata[i][j];
            data[i][j] += data2.mdata[i][j];
            data[i][j] += data3.mdata[i][j];
        }
    }
displayMatrix(data, "F i n a l", 1);

//--------------------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------ O u t p u t   f i l e   r e p o r t   g e n e r a t o r -----------------------------------------------------
    std::ofstream outputFile(outputTxt);
    std::ifstream sourceFile1(file1);
    std::ifstream sourceFile2(file2);
    std::ifstream sourceFile3(file3);

    // Vanity code, totally unnecessary
    oout << "_________________________________________________________________" << endl;
    oout<<"\n          T A B L E   T O   M A T R I X   R E P O R T" << endl;
    oout << "_________________________________________________________________" << endl;
    std::time_t currentTime = std::time(0);
    std::tm* localTime = std::localtime(&currentTime);
    const char* daysOfWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    const char* monthAbbreviations[] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun", 
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    outputFile << "Time of report generation:\t" 
                    << std::setfill('0') << localTime->tm_mday
                    << "-" << std::setfill('0') << monthAbbreviations[localTime->tm_mon]
                    << "-" << std::setfill('0') << localTime->tm_year + 1900
                    << " "
                    << " " << std::setfill('0') << std::setw(2) << localTime->tm_hour
                    << ":" << std::setfill('0') << std::setw(2) << localTime->tm_min
                    << ":" << std::setfill('0') << std::setw(2) << localTime->tm_sec
                    << " "
                    << "(" << daysOfWeek[localTime->tm_wday] << ")" << endl;
                  

    outputFile << "Location of data:\t\t\t" << location << endl;
    oout << "_________________________________________________________________\n" << endl;
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
    oout << "raw1 Index: " << data1.dataIndex << endl;
    oout << "raw2 Index: " << data2.dataIndex << endl;
    oout << "raw3 Index: " << data3.dataIndex << endl;
    oout << "\n\n";

    // Display copied and sorted data (sort by x-coordinate)
    oout << ">data1 (sorted by x-axis in ascending order)" << endl;
    if(data1.dataIndex>0){
        for(int i=0;i<data1.dataIndex;i++){
            for(int j=0;j<2;j++){
               oout << dataV1[i][j] << " ";
            }
            oout << " | "; //"\n";
        }
    }
    else{oout << "Empty data!" << endl;}
    oout << "\n\n";
    oout << ">data2 (sorted by x-axis in ascending order)" << endl;
    if(data2.dataIndex>0){
        for(int i=0;i<data2.dataIndex;i++){
            for(int j=0;j<2;j++){
               oout << dataV2[i][j] << " ";
            }
            oout << " | "; //"\n";
        }
    }
    else{oout << "Empty data!" << endl;}
    oout << "\n\n";
    oout << ">data3 (sorted by x-axis in ascending order)" << endl;
    if(data3.dataIndex>0){
        for(int i=0;i<data3.dataIndex;i++){
            for(int j=0;j<2;j++){
               oout << dataV3[i][j] << " ";
            }
            oout << " | "; //"\n";
        }
    }
    else{oout << "Empty data!" << endl;}
    oout << "\n\n";

    // Display preliminary report
    oout << "-----------------------------------------------------------------" << endl;
    oout << "--------- P R E L I M I N A R Y     R E P O R T -----------------" << endl;
    if(data1.dataIndex>0){
    oout << "---------------------- R E P O R T   1 --------------------------" << endl;
    oout << "number of indexes found: " << data1.dataIndex << endl;
    oout << "[\t";
    for(int i=0;i<6;i++){
    oout << data1.xcoord[i] << "\t";
    }oout << "]" << endl;
    oout << " " << data1.difference << " distinct x-coordinates found!" << endl;
    }
    else{oout << "Empty data! No coordinates found!" << endl;}
    oout << "-----------------------------------------------------------------\n" << endl;

    if(data2.dataIndex>0){
    oout << "---------------------- R E P O R T   2 --------------------------" << endl;
    oout << "number of indexes found: " << data2.dataIndex << endl;
    oout << "[\t";
    for(int i=0;i<6;i++){
    oout << data2.xcoord[i] << "\t";
    }oout << "]" << endl;
    oout << " " << data2.difference << " distinct x-coordinates found!" << endl;
    }
    else{oout << "Empty data! No coordinates found!" << endl;}
    oout << "-----------------------------------------------------------------\n" << endl;

    if(data3.dataIndex>0){
    oout << "---------------------- R E P O R T   3 --------------------------" << endl;
    oout << "number of indexes found: " << data3.dataIndex << endl;
    oout << "[\t";
    for(int i=0;i<6;i++){
    oout << data3.xcoord[i] << "\t";
    }oout << "]" << endl;
    oout << " " << data3.difference << " distinct x-coordinates found!" << endl;
    }
    else{oout << "Empty data! No coordinates found!" << endl;}
    oout << "-----------------------------------------------------------------\n" << endl;

    // Displaying y-coordinates
    oout << "\n-----------------------------------------------------------------" << endl;
    oout << "  DISPLAYING LIST OF Y-COORDINATES FOR EACH RESPECTIVE X-AXIS " << endl;
    oout << "-----------------------------------------------------------------";
    oout << "\ndata1 y-coord: ";
    for(int i=0;i<6;i++){
        oout << "\nx"<< i+1 << "00A: ";
        for(int j=0;j<data1.xcoord[i];j++){                 // get xcoord y-coordinate for data1
            oout << xcoord[0][i][j] << " ";                 // x location = 100
        }
    }
    oout << "\ndata2 y-coord: ";
    for(int i=0;i<6;i++){
        oout << "\nx"<< i+1 << "00B: ";
        for(int j=0;j<data2.xcoord[i];j++){                 // get xcoord y-coordinate for data2
            oout << xcoord[1][i][j] << " ";                 // x location = 100
        }
    }
    oout << "\ndata3 y-coord: ";
    for(int i=0;i<6;i++){
        oout << "\nx"<< i+1 << "00C: ";
        for(int j=0;j<data3.xcoord[i];j++){                 // get xcoord y-coordinate for data2
            oout << xcoord[2][i][j] << " ";                 // x location = 100
        }
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
            if(data1.mdata[j][i]==0 && _toggleClear){oout << "\t";}
            else{oout << data1.mdata[j][i] << "\t";}
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
            if(data2.mdata[j][i]==0 && _toggleClear){oout << "\t";}
            else{oout << data2.mdata[j][i] << "\t";}
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
            if(data3.mdata[j][i]==0 && _toggleClear){oout << "\t";}
            else{oout << data3.mdata[j][i] << "\t";}
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
    
    // Close the file
    outputFile.close();
    
    cout << "\nData has been written to output.txt\nReport generated" << endl;
   
    closing();

return 0;

}


