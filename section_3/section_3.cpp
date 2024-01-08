#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <stdio.h>


#define cout std::cout
#define endl std::endl
const std::size_t MAX_SIZE = 1;

void _sort(int arr[], int size);
void appendMatrix(int arr[], int size, int xloc);
void displayMatrix();

template <std::size_t Rows, std::size_t Cols>
int getIndex(int(&array)[Rows][Cols]){
    return Rows;
}

//---------------------------------- V a r i a b l e s ---------------------------------
int row = 6;
int col = 6;
int data[6][6] = {{0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  };
int threshold = 30;
//--------------------------------------------------------------------------------------

int main() {

//int raw1[][2] = {{0, 0}, {100, 98}, {99, 99}, {100, 99}, {101, 99}, {98, 100}, {99, 100}, {100, 100}, {101, 100}, {102, 100}, {97, 101}, {98, 101}, {99, 101}, {100, 101}, {101, 101}, {102, 101}, {103, 101}, {98, 102}, {99, 102}, {100, 102}, {101, 102}, {102, 102}, {99, 103}, {100, 103}, {101, 103}, {100, 104}, {600, 197}, {599, 198}, {600, 198}, {601, 198}, {598, 199}, {599, 199}, {600, 199}, {601, 199}, {602, 199}, {597, 200}, {598, 200}, {599, 200}, {600, 200}, {601, 200}, {602, 200}, {603, 200}, {598, 201}, {599, 201}, {600, 201}, {601, 201}, {602, 201}, {599, 202}, {600, 202}, {601, 202}, {600, 203}, {300, 297}, {299, 298}, {300, 298}, {301, 298}, {298, 299}, {299, 299}, {300, 299}, {301, 299}, {302, 299}, {297, 300}, {298, 300}, {299, 300}, {300, 300}, {301, 300}, {302, 300}, {303, 300}, {298, 301}, {299, 301}, {300, 301}, {301, 301}, {302, 301}, {299, 302}, {300, 302}, {301, 302}, {300, 303}, {400, 497}, {399, 498}, {400, 498}, {401, 498}, {398, 499}, {399, 499}, {400, 499}, {401, 499}, {402, 499}, {397, 500}, {398, 500}, {399, 500}, {400, 500}, {401, 500}, {402, 500}, {403, 500}, {398, 501}, {399, 501}, {400, 501}, {401, 501}, {402, 501}, {399, 502}, {400, 502}, {401, 502}, {400, 503}};
//int raw1[][2] = {{0, 0}, {300, 197}, {600, 197}, {299, 198}, {300, 198}, {301, 198}, {599, 198}, {600, 198}, {601, 198}, {298, 199}, {299, 199}, {300, 199}, {301, 199}, {302, 199}, {598, 199}, {599, 199}, {600, 199}, {601, 199}, {602, 199}, {297, 200}, {298, 200}, {299, 200}, {300, 200}, {301, 200}, {302, 200}, {303, 200}, {597, 200}, {598, 200}, {599, 200}, {600, 200}, {601, 200}, {602, 200}, {603, 200}, {298, 201}, {299, 201}, {300, 201}, {301, 201}, {302, 201}, {598, 201}, {599, 201}, {600, 201}, {601, 201}, {602, 201}, {299, 202}, {300, 202}, {301, 202}, {599, 202}, {600, 202}, {601, 202}, {300, 203}, {600, 203}, {500, 297}, {499, 298}, {500, 298}, {501, 298}, {498, 299}, {499, 299}, {500, 299}, {501, 299}, {502, 299}, {497, 300}, {498, 300}, {499, 300}, {500, 300}, {501, 300}, {502, 300}, {503, 300}, {498, 301}, {499, 301}, {500, 301}, {501, 301}, {502, 301}, {499, 302}, {500, 302}, {501, 302}, {500, 303}, {200, 397}, {199, 398}, {200, 398}, {201, 398}, {198, 399}, {199, 399}, {200, 399}, {201, 399}, {202, 399}, {197, 400}, {198, 400}, {199, 400}, {200, 400}, {201, 400}, {202, 400}, {203, 400}, {198, 401}, {199, 401}, {200, 401}, {201, 401}, {202, 401}, {199, 402}, {200, 402}, {201, 402}, {200, 403}, {200, 598}, {199, 599}, {200, 599}, {201, 599}, {198, 600}, {199, 600}, {200, 600}, {201, 600}, {202, 600}, {197, 601}, {198, 601}, {199, 601}, {200, 601}, {201, 601}, {202, 601}, {203, 601}, {198, 602}, {199, 602}, {200, 602}, {201, 602}, {202, 602}, {199, 603}, {200, 603}, {201, 603}, {200, 604}};
int raw1[][2] = {{0, 0}, {200, 197}, {600, 197}, {199, 198}, {200, 198}, {201, 198}, {599, 198}, {600, 198}, {601, 198}, {198, 199}, {199, 199}, {200, 199}, {201, 199}, {202, 199}, {598, 199}, {599, 199}, {600, 199}, {601, 199}, {602, 199}, {197, 200}, {198, 200}, {199, 200}, {200, 200}, {201, 200}, {202, 200}, {203, 200}, {597, 200}, {598, 200}, {599, 200}, {600, 200}, {601, 200}, {602, 200}, {603, 200}, {198, 201}, {199, 201}, {200, 201}, {201, 201}, {202, 201}, {598, 201}, {599, 201}, {600, 201}, {601, 201}, {602, 201}, {199, 202}, {200, 202}, {201, 202}, {599, 202}, {600, 202}, {601, 202}, {200, 203}, {600, 203}, {400, 297}, {399, 298}, {400, 298}, {401, 298}, {398, 299}, {399, 299}, {400, 299}, {401, 299}, {402, 299}, {397, 300}, {398, 300}, {399, 300}, {400, 300}, {401, 300}, {402, 300}, {403, 300}, {398, 301}, {399, 301}, {400, 301}, {401, 301}, {402, 301}, {399, 302}, {400, 302}, {401, 302}, {400, 303}, {400, 397}, {399, 398}, {400, 398}, {401, 398}, {398, 399}, {399, 399}, {400, 399}, {401, 399}, {402, 399}, {397, 400}, {398, 400}, {399, 400}, {400, 400}, {401, 400}, {402, 400}, {403, 400}, {398, 401}, {399, 401}, {400, 401}, {401, 401}, {402, 401}, {399, 402}, {400, 402}, {401, 402}, {400, 403}, {200, 597}, {199, 598}, {200, 598}, {201, 598}, {198, 599}, {199, 599}, {200, 599}, {201, 599}, {202, 599}, {197, 600}, {198, 600}, {199, 600}, {200, 600}, {201, 600}, {202, 600}, {203, 600}, {198, 601}, {199, 601}, {200, 601}, {201, 601}, {202, 601}, {199, 602}, {200, 602}, {201, 602}, {200, 603}};
int raw2[][2] = {{0, 0}};
int raw3[][2] = {{0, 0}};

//---------------------- P r o c e s s   &   a p p e n d   r a w   d a t a -------------------------------
//int raw1_i = sizeof(raw1) / sizeof(raw1[0]);              // manually get dimension1 index size
//int raw2_i = sizeof(raw2) / sizeof(raw2[0]);              // manually get dimension1 index size
//int raw3_i = sizeof(raw3) / sizeof(raw3[0]);              // manually get dimension1 index size
cout << "raw1 index: " << getIndex(raw1) << endl;
cout << "raw2 index: " << getIndex(raw2) << endl;
cout << "raw3 index: " << getIndex(raw3) << endl;

int data1_Index = getIndex(raw1);
int data2_Index = getIndex(raw2);
int data3_Index = getIndex(raw3);

int data1[getIndex(raw1)][2];                   // declaring data1
int data2[getIndex(raw2)][2];                   // declaring data2
int data3[getIndex(raw3)][2];                   // declaring data3

for (int i=0;i<data1_Index;i++){
    for(int j=0;j<2;j++){
        data1[i][j] = raw1[i][j];
    }
}
for (int i=0;i<data2_Index;i++){
    for(int j=0;j<2;j++){
        data2[i][j] = raw2[i][j];
    }
}
for (int i=0;i<data3_Index;i++){
    for(int j=0;j<2;j++){
        data3[i][j] = raw3[i][j];
    }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------- s o r t   b y   x - c o o r d i n a t e   i n   a s c e n d i n g   o r d e r ---------------------------------
//std::sort(&data1[0][0], &data1[0][0] + data1_Index * 2, [](int a, int b) {return a < b;});
//std::sort(&data2[0][0], &data2[0][0] + data2_Index * 2, [](int a, int b) {return a < b;});
//std::sort(&data3[0][0], &data3[0][0] + data3_Index * 2, [](int a, int b) {return a < b;});

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

for(int i=0;i<data1_Index;i++){
    for(int j=0;j<2;j++){
        cout << data1[i][j] << " ";
    }
    cout << "\n";
}
cout << "\n data2" << endl;
for(int i=0;i<data2_Index;i++){
    for(int j=0;j<2;j++){
        cout << data2[i][j] << " ";
    }
    cout << "\n";
}
cout << "\n data3" << endl;
for(int i=0;i<data3_Index;i++){
    for(int j=0;j<2;j++){
        cout << data3[i][j] << " ";
    }
    cout << "\n";
}cout << "\n";
//-----------------------------------------------------------------------------------------------------------------------------------------------------
int xcoord1[6] = {0, 0, 0, 0, 0, 0};
int xcoord2[6] = {0, 0, 0, 0, 0, 0};
int xcoord3[6] = {0, 0, 0, 0, 0, 0};

int xcoord1Jump[1] = {0};              // indexes where distinct data appears

int difference[3] = {1, 1, 1}; // number of distinct data, every data must have at least 1 distinct data, 1st index for raw1, 2nd index for raw2, 3rd index for raw3

for(int i=0;i<data1_Index;i++){
    static int indx = 0;
    static int placeIndex = 0;                          // static int, when running in loop, it will only declare once and not reset the value
    if(data1[i][0]==0){                                 //filter out (0, 0)
        cout << "zero!!" << endl;
        }      
    //else if(i==data1_Index-1){}                       // skip last index
    else if(data1[i+1][0]-data1[i][0]<threshold){       // same value
        indx = round(static_cast<double>(data1[i][0])/100.0)-1;
        //cout << indx << endl;
        xcoord1[indx]++;
    }
    else{                                               // different value, jump
        indx = round(static_cast<double>(data1[i][0])/100.0)-1;
        xcoord1[indx]++;

        if(i!=data1_Index-1){
            difference[0]++;          // avoid appending difference when approaching last index, lastIndex+1 does not exist therefore should not count as one difference
            cout << "found 1 difference! current difference: " << difference[0] << ", current index: " << i << endl;
            xcoord1Jump[difference[0]-1] = i;
        }
    }
}


//------------------------------------------ append y-coordinates into each respective column ---------------------------------
int x100[xcoord1[0]];
int x200[xcoord1[1]];
int x300[xcoord1[2]];
int x400[xcoord1[3]];
int x500[xcoord1[4]];
int x600[xcoord1[5]];


for(int i=0;i<xcoord1[0];i++){
    x100[i]=data1[i+1][1];
}
for(int i=0;i<xcoord1[1];i++){
    x200[i]=data1[i+1+xcoord1[0]][1];
}
for(int i=0;i<xcoord1[2];i++){
    x300[i]=data1[i+1+xcoord1[0]+xcoord1[1]][1];
}
for(int i=0;i<xcoord1[3];i++){
    x400[i]=data1[i+1+xcoord1[0]+xcoord1[1]+xcoord1[2]][1];
}
for(int i=0;i<xcoord1[4];i++){
    x500[i]=data1[i+1+xcoord1[0]+xcoord1[1]+xcoord1[2]+xcoord1[3]][1];
}
for(int i=0;i<xcoord1[5];i++){
    x600[i]=data1[i+1+xcoord1[0]+xcoord1[1]+xcoord1[2]+xcoord1[3]+xcoord1[4]][1];
}
//----------------------------------------------------------------------------------------------------------------------------

//---------------------------------- s o r t   b y   y - c o o r d i n a t e   i n   a s c e n d i n g   o r d e r ---------------------------------
_sort(x100, xcoord1[0]);
_sort(x200, xcoord1[1]);
_sort(x300, xcoord1[2]);
_sort(x400, xcoord1[3]);
_sort(x500, xcoord1[4]);
_sort(x600, xcoord1[5]);
//--------------------------------------------------------------------------------------------------------------------------------------------------

appendMatrix(x100, xcoord1[0], 0);
appendMatrix(x200, xcoord1[1], 1);
appendMatrix(x300, xcoord1[2], 2);
appendMatrix(x400, xcoord1[3], 3);
appendMatrix(x500, xcoord1[4], 4);
appendMatrix(x600, xcoord1[5], 5);


//set data1 into 1
for(int i=0;i<6;i++){
    for(int j=0;j<6;j++){
        if(data[i][j]!=0){
            data[i][j]=1;
        }
    }
}

//------------------------------------- display appended y-coordinates --------------------------------------------
//cout << x100[0] << endl;
cout << "\ndata1 y-coord: ";

cout << "\nx100: ";
for(int i=0;i<xcoord1[0];i++){              // get xcoord y-coordinate for raw1
    cout << x100[i] << " ";                 // x location = 100
}

cout << "\nx200: ";
for(int i=0;i<xcoord1[1];i++){
    cout << x200[i] << " ";
}

cout << "\nx300: ";
for(int i=0;i<xcoord1[2];i++){
    cout << x300[i] << " ";
}

cout << "\nx400: ";
for(int i=0;i<xcoord1[3];i++){
    cout << x400[i] << " ";
}

cout << "\nx500: ";
for(int i=0;i<xcoord1[4];i++){
    cout << x500[i] << " ";
}

cout << "\nx600: ";
for(int i=0;i<xcoord1[5];i++){
    cout << x600[i] << " ";
}
//------------------------------------------------------------------------------------------------------------------


/*


for(int i=0;i<xcoord[0]+1;i++){
    x100[i] = data1[i][1];
}
for(int i=0;i<xcoord[1]+1;i++){
    x200[i] = data1[i+1+xcoord[0]][1];
}
for(int i=0;i<xcoord[2]+1;i++){
    x300[i] = data1[i+1+xcoord[0]+xcoord[1]][1];
}
for(int i=0;i<xcoord[3]+1;i++){
    x400[i] = data1[i+1+xcoord[0]+xcoord[1]+xcoord[2]][1];
}
for(int i=0;i<xcoord[4]+1;i++){
    x500[i] = data1[i+1+xcoord[0]+xcoord[1]+xcoord[2]+xcoord[3]][1];
}
for(int i=0;i<xcoord[5];i++){
    x600[i] = data1[i+1+xcoord[0]+xcoord[1]+xcoord[2]+xcoord[3]+xcoord[4]][1];
}


*/
/*
for(int i=0;i<difference;i++){                      // loop n times where it contains different number of x-locations
    while(data1[i+1][0]-data1[i][0]<threshold){     // while x-coordinate whithin range (absolute x)
        if(data1[i+1][1]<data1[i][1]){
            int tempdata[2];
            tempdata[0]=data1[i][0];
            tempdata[1]=data1[i][1];

            data1[i][0]=data1[i+1][0];
            data1[i][1]=data1[i+1][1];
    
            data1[i+1][0]=tempdata[0];
            data1[i+1][1]=tempdata[1];
        }
}}*/

cout << "\n\n{ " ;
for(int i=0;i<6;i++){
    cout << xcoord1[i] << "\t";
}cout << "}" << endl;
/*
cout << "\n{ " ;
for(int i=0;i<6;i++){
    cout << ycoord1[i] << "\t";
}cout << "}" << endl;
*/





cout << "\n" << difference[0] << " distinct x-coordinates found!" << endl;
//cout << "\n" << ydifference << " distinct y-coordinates found across x100!" << endl;

for(int i=0;i<6;i++){               // dont care the unknown indexes, get every index+1, if index number later 0 is 0, ignore, maximum contain 6 distinct location
    cout << "jump index " << i+1 << " : " << xcoord1Jump[i] << endl;
}


    cout << "\n";

    displayMatrix();

    return 0;
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



void appendMatrix(int arr[], int size, int xloc){
//x100
//int ycoord1[6] = {0, 0, 0, 0, 0, 0};
//int ydifference = 1;
for(int i=0;i<size;i++){
    //ycoord1[indx]++;
    if(arr[i]==0){                                 //filter out (0, 0)
        cout << "zero!!" << endl;
    }
    else{
        int indx = int((round(static_cast<double>(arr[i])/100.0)-1));
        data[indx][xloc]++;
        }
    }
}

void displayMatrix(){
    cout << "\tR1\tR2\tR3\tR4\tR5\tNS" << endl;
    for(int j=0;j<6;j++){
        if(j<4){
            cout << "D\t";
        }
        else{cout << "R\t";}
        for(int i=0;i<6;i++){
            cout << data[j][i] << "\t";
        }
        cout << "\n";
    }
}
