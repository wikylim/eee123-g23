#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <stdio.h>


#define cout std::cout
#define endl std::endl
const std::size_t MAX_SIZE = 1;

void _sort(int arr[], int size);
void appendMatrix1(int arr[], int size, int xloc);
void appendMatrix2(int arr[], int size, int xloc);
void displayMatrix();

template <std::size_t Rows, std::size_t Cols>
int getIndex(int(&array)[Rows][Cols]){
    return Rows;
}

//---------------------------------- V a r i a b l e s ---------------------------------
const int threshold = 30;

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

int main() {

//int raw1[][2] = {{0, 0}, {100, 98}, {99, 99}, {100, 99}, {101, 99}, {98, 100}, {99, 100}, {100, 100}, {101, 100}, {102, 100}, {97, 101}, {98, 101}, {99, 101}, {100, 101}, {101, 101}, {102, 101}, {103, 101}, {98, 102}, {99, 102}, {100, 102}, {101, 102}, {102, 102}, {99, 103}, {100, 103}, {101, 103}, {100, 104}, {600, 197}, {599, 198}, {600, 198}, {601, 198}, {598, 199}, {599, 199}, {600, 199}, {601, 199}, {602, 199}, {597, 200}, {598, 200}, {599, 200}, {600, 200}, {601, 200}, {602, 200}, {603, 200}, {598, 201}, {599, 201}, {600, 201}, {601, 201}, {602, 201}, {599, 202}, {600, 202}, {601, 202}, {600, 203}, {300, 297}, {299, 298}, {300, 298}, {301, 298}, {298, 299}, {299, 299}, {300, 299}, {301, 299}, {302, 299}, {297, 300}, {298, 300}, {299, 300}, {300, 300}, {301, 300}, {302, 300}, {303, 300}, {298, 301}, {299, 301}, {300, 301}, {301, 301}, {302, 301}, {299, 302}, {300, 302}, {301, 302}, {300, 303}, {400, 497}, {399, 498}, {400, 498}, {401, 498}, {398, 499}, {399, 499}, {400, 499}, {401, 499}, {402, 499}, {397, 500}, {398, 500}, {399, 500}, {400, 500}, {401, 500}, {402, 500}, {403, 500}, {398, 501}, {399, 501}, {400, 501}, {401, 501}, {402, 501}, {399, 502}, {400, 502}, {401, 502}, {400, 503}};
//int raw1[][2] = {{0, 0}, {300, 197}, {600, 197}, {299, 198}, {300, 198}, {301, 198}, {599, 198}, {600, 198}, {601, 198}, {298, 199}, {299, 199}, {300, 199}, {301, 199}, {302, 199}, {598, 199}, {599, 199}, {600, 199}, {601, 199}, {602, 199}, {297, 200}, {298, 200}, {299, 200}, {300, 200}, {301, 200}, {302, 200}, {303, 200}, {597, 200}, {598, 200}, {599, 200}, {600, 200}, {601, 200}, {602, 200}, {603, 200}, {298, 201}, {299, 201}, {300, 201}, {301, 201}, {302, 201}, {598, 201}, {599, 201}, {600, 201}, {601, 201}, {602, 201}, {299, 202}, {300, 202}, {301, 202}, {599, 202}, {600, 202}, {601, 202}, {300, 203}, {600, 203}, {500, 297}, {499, 298}, {500, 298}, {501, 298}, {498, 299}, {499, 299}, {500, 299}, {501, 299}, {502, 299}, {497, 300}, {498, 300}, {499, 300}, {500, 300}, {501, 300}, {502, 300}, {503, 300}, {498, 301}, {499, 301}, {500, 301}, {501, 301}, {502, 301}, {499, 302}, {500, 302}, {501, 302}, {500, 303}, {200, 397}, {199, 398}, {200, 398}, {201, 398}, {198, 399}, {199, 399}, {200, 399}, {201, 399}, {202, 399}, {197, 400}, {198, 400}, {199, 400}, {200, 400}, {201, 400}, {202, 400}, {203, 400}, {198, 401}, {199, 401}, {200, 401}, {201, 401}, {202, 401}, {199, 402}, {200, 402}, {201, 402}, {200, 403}, {200, 598}, {199, 599}, {200, 599}, {201, 599}, {198, 600}, {199, 600}, {200, 600}, {201, 600}, {202, 600}, {197, 601}, {198, 601}, {199, 601}, {200, 601}, {201, 601}, {202, 601}, {203, 601}, {198, 602}, {199, 602}, {200, 602}, {201, 602}, {202, 602}, {199, 603}, {200, 603}, {201, 603}, {200, 604}};
int raw1[][2] = {{0, 0}, {200, 197}, {600, 197}, {199, 198}, {200, 198}, {201, 198}, {599, 198}, {600, 198}, {601, 198}, {198, 199}, {199, 199}, {200, 199}, {201, 199}, {202, 199}, {598, 199}, {599, 199}, {600, 199}, {601, 199}, {602, 199}, {197, 200}, {198, 200}, {199, 200}, {200, 200}, {201, 200}, {202, 200}, {203, 200}, {597, 200}, {598, 200}, {599, 200}, {600, 200}, {601, 200}, {602, 200}, {603, 200}, {198, 201}, {199, 201}, {200, 201}, {201, 201}, {202, 201}, {598, 201}, {599, 201}, {600, 201}, {601, 201}, {602, 201}, {199, 202}, {200, 202}, {201, 202}, {599, 202}, {600, 202}, {601, 202}, {200, 203}, {600, 203}, {400, 297}, {399, 298}, {400, 298}, {401, 298}, {398, 299}, {399, 299}, {400, 299}, {401, 299}, {402, 299}, {397, 300}, {398, 300}, {399, 300}, {400, 300}, {401, 300}, {402, 300}, {403, 300}, {398, 301}, {399, 301}, {400, 301}, {401, 301}, {402, 301}, {399, 302}, {400, 302}, {401, 302}, {400, 303}, {400, 397}, {399, 398}, {400, 398}, {401, 398}, {398, 399}, {399, 399}, {400, 399}, {401, 399}, {402, 399}, {397, 400}, {398, 400}, {399, 400}, {400, 400}, {401, 400}, {402, 400}, {403, 400}, {398, 401}, {399, 401}, {400, 401}, {401, 401}, {402, 401}, {399, 402}, {400, 402}, {401, 402}, {400, 403}, {200, 597}, {199, 598}, {200, 598}, {201, 598}, {198, 599}, {199, 599}, {200, 599}, {201, 599}, {202, 599}, {197, 600}, {198, 600}, {199, 600}, {200, 600}, {201, 600}, {202, 600}, {203, 600}, {198, 601}, {199, 601}, {200, 601}, {201, 601}, {202, 601}, {199, 602}, {200, 602}, {201, 602}, {200, 603}};

int raw2[][2] = {{0, 0}, {200, 97}, {199, 98}, {200, 98}, {201, 98}, {198, 99}, {199, 99}, {200, 99}, {201, 99}, {202, 99}, {197, 100}, {198, 100}, {199, 100}, {200, 100}, {201, 100}, {202, 100}, {203, 100}, {198, 101}, {199, 101}, {200, 101}, {201, 101}, {202, 101}, {199, 102}, {200, 102}, {201, 102}, {200, 103}, {100, 197}, {400, 197}, {99, 198}, {100, 198}, {101, 198}, {399, 198}, {400, 198}, {401, 198}, {98, 199}, {99, 199}, {100, 199}, {101, 199}, {102, 199}, {398, 199}, {399, 199}, {400, 199}, {401, 199}, {402, 199}, {97, 200}, {98, 200}, {99, 200}, {100, 200}, {101, 200}, {102, 200}, {103, 200}, {397, 200}, {398, 200}, {399, 200}, {400, 200}, {401, 200}, {402, 200}, {403, 200}, {98, 201}, {99, 201}, {100, 201}, {101, 201}, {102, 201}, {398, 201}, {399, 201}, {400, 201}, {401, 201}, {402, 201}, {99, 202}, {100, 202}, {101, 202}, {399, 202}, {400, 202}, {401, 202}, {100, 203}, {400, 203}, {600, 397}, {200, 398}, {599, 398}, {600, 398}, {601, 398}, {199, 399}, {200, 399}, {201, 399}, {598, 399}, {599, 399}, {600, 399}, {601, 399}, {602, 399}, {198, 400}, {199, 400}, {200, 400}, {201, 400}, {202, 400}, {597, 400}, {598, 400}, {599, 400}, {600, 400}, {601, 400}, {602, 400}, {603, 400}, {197, 401}, {198, 401}, {199, 401}, {200, 401}, {201, 401}, {202, 401}, {203, 401}, {598, 401}, {599, 401}, {600, 401}, {601, 401}, {602, 401}, {198, 402}, {199, 402}, {200, 402}, {201, 402}, {202, 402}, {599, 402}, {600, 402}, {601, 402}, {199, 403}, {200, 403}, {201, 403}, {600, 403}, {200, 404}, {400, 497}, {399, 498}, {400, 498}, {401, 498}, {398, 499}, {399, 499}, {400, 499}, {401, 499}, {402, 499}, {397, 500}, {398, 500}, {399, 500}, {400, 500}, {401, 500}, {402, 500}, {403, 500}, {398, 501}, {399, 501}, {400, 501}, {401, 501}, {402, 501}, {399, 502}, {400, 502}, {401, 502}, {400, 503}, {600, 597}, {599, 598}, {600, 598}, {601, 598}, {598, 599}, {599, 599}, {600, 599}, {601, 599}, {602, 599}, {597, 600}, {598, 600}, {599, 600}, {600, 600}, {601, 600}, {602, 600}, {603, 600}, {598, 601}, {599, 601}, {600, 601}, {601, 601}, {602, 601}, {599, 602}, {600, 602}, {601, 602}, {600, 603}};
//int raw2[][2] = {{0, 0}};
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
cout << "\n data1" << endl;
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

//-----debugging variables----------
int xcoord1Jump[1] = {0};                               // indexes where distinct data appears
int xcoord2Jump[1] = {0}; 
int xcoord3Jump[1] = {0}; 

int difference[3] = {1, 1, 1}; // number of distinct data, every data must have at least 1 distinct data, 1st index for raw1, 2nd index for raw2, 3rd index for raw3
//----------------------------------
cout << "---------------------- R E P O R T   1 ----------------------" << endl;
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
cout << "\n{ " ;
for(int i=0;i<6;i++){
    cout << xcoord1[i] << "\t";
}cout << "}" << endl;
cout << "\n" << difference[0] << " distinct x-coordinates found!" << endl;
cout << "-------------------------------------------------------------" << endl;

cout << "---------------------- R E P O R T   2 ----------------------" << endl;
for(int i=0;i<data2_Index;i++){
    static int indx = 0;
    static int placeIndex = 0;                          // static int, when running in loop, it will only declare once and not reset the value
    if(data2[i][0]==0){                                 //filter out (0, 0)
        cout << "zero!!" << endl;
        }      
    //else if(i==data1_Index-1){}                       // skip last index
    else if(data2[i+1][0]-data2[i][0]<threshold){       // same value
        indx = round(static_cast<double>(data2[i][0])/100.0)-1;
        //cout << indx << endl;
        xcoord2[indx]++;
    }
    else{                                               // different value, jump
        indx = round(static_cast<double>(data2[i][0])/100.0)-1;
        xcoord2[indx]++;

        if(i!=data2_Index-1){
            difference[1]++;          // avoid appending difference when approaching last index, lastIndex+1 does not exist therefore should not count as one difference
            cout << "found 1 difference! current difference: " << difference[1] << ", current index: " << i << endl;
            xcoord2Jump[difference[1]-1] = i;
        }
    }
}
cout << "\n{ " ;
for(int i=0;i<6;i++){
    cout << xcoord2[i] << "\t";
}cout << "}" << endl;
cout << "\n" << difference[1] << " distinct x-coordinates found!" << endl;
cout << "-------------------------------------------------------------" << endl;

//------------------------------------------ append y-coordinates into each respective column ---------------------------------
int x100A[xcoord1[0]];
int x200A[xcoord1[1]];
int x300A[xcoord1[2]];
int x400A[xcoord1[3]];
int x500A[xcoord1[4]];
int x600A[xcoord1[5]];
for(int i=0;i<xcoord1[0];i++){
    x100A[i]=data1[i+1][1];
}
for(int i=0;i<xcoord1[1];i++){
    x200A[i]=data1[i+1+xcoord1[0]][1];
}
for(int i=0;i<xcoord1[2];i++){
    x300A[i]=data1[i+1+xcoord1[0]+xcoord1[1]][1];
}
for(int i=0;i<xcoord1[3];i++){
    x400A[i]=data1[i+1+xcoord1[0]+xcoord1[1]+xcoord1[2]][1];
}
for(int i=0;i<xcoord1[4];i++){
    x500A[i]=data1[i+1+xcoord1[0]+xcoord1[1]+xcoord1[2]+xcoord1[3]][1];
}
for(int i=0;i<xcoord1[5];i++){
    x600A[i]=data1[i+1+xcoord1[0]+xcoord1[1]+xcoord1[2]+xcoord1[3]+xcoord1[4]][1];
}

int x100B[xcoord2[0]];
int x200B[xcoord2[1]];
int x300B[xcoord2[2]];
int x400B[xcoord2[3]];
int x500B[xcoord2[4]];
int x600B[xcoord2[5]];
for(int i=0;i<xcoord2[0];i++){
    x100B[i]=data2[i+1][1];
}
for(int i=0;i<xcoord2[1];i++){
    x200B[i]=data2[i+1+xcoord2[0]][1];
}
for(int i=0;i<xcoord2[2];i++){
    x300B[i]=data2[i+1+xcoord2[0]+xcoord2[1]][1];
}
for(int i=0;i<xcoord2[3];i++){
    x400B[i]=data2[i+1+xcoord2[0]+xcoord2[1]+xcoord2[2]][1];
}
for(int i=0;i<xcoord2[4];i++){
    x500B[i]=data2[i+1+xcoord2[0]+xcoord2[1]+xcoord2[2]+xcoord2[3]][1];
}
for(int i=0;i<xcoord2[5];i++){
    x600B[i]=data2[i+1+xcoord2[0]+xcoord2[1]+xcoord2[2]+xcoord2[3]+xcoord2[4]][1];
}

//----------------------------------------------------------------------------------------------------------------------------

//---------------------------------- s o r t   b y   y - c o o r d i n a t e   i n   a s c e n d i n g   o r d e r ---------------------------------
_sort(x100A, xcoord1[0]);
_sort(x200A, xcoord1[1]);
_sort(x300A, xcoord1[2]);
_sort(x400A, xcoord1[3]);
_sort(x500A, xcoord1[4]);
_sort(x600A, xcoord1[5]);

_sort(x100B, xcoord2[0]);
_sort(x200B, xcoord2[1]);
_sort(x300B, xcoord2[2]);
_sort(x400B, xcoord2[3]);
_sort(x500B, xcoord2[4]);
_sort(x600B, xcoord2[5]);

//--------------------------------------------------------------------------------------------------------------------------------------------------

appendMatrix1(x100A, xcoord1[0], 0);
appendMatrix1(x200A, xcoord1[1], 1);
appendMatrix1(x300A, xcoord1[2], 2);
appendMatrix1(x400A, xcoord1[3], 3);
appendMatrix1(x500A, xcoord1[4], 4);
appendMatrix1(x600A, xcoord1[5], 5);

appendMatrix2(x100B, xcoord2[0], 0);
appendMatrix2(x200B, xcoord2[1], 1);
appendMatrix2(x300B, xcoord2[2], 2);
appendMatrix2(x400B, xcoord2[3], 3);
appendMatrix2(x500B, xcoord2[4], 4);
appendMatrix2(x600B, xcoord2[5], 5);


//set data1 into 1
for(int i=0;i<6;i++){
    for(int j=0;j<6;j++){
        if(dataA[i][j]!=0){
            dataA[i][j]=1;
        }
    }
}

//set data2 into 2
for(int i=0;i<6;i++){
    for(int j=0;j<6;j++){
        if(dataB[i][j]!=0){
            dataB[i][j]=2;
        }
    }
}


//------------------------------------- display appended y-coordinates --------------------------------------------
//cout << x100A[0] << endl;
cout << "\ndata1 y-coord: ";
cout << "\nx100A: ";
for(int i=0;i<xcoord1[0];i++){              // get xcoord y-coordinate for raw1
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
for(int i=0;i<xcoord2[0];i++){              // get xcoord y-coordinate for raw2
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

//------------------------------------------------------------------------------------------------------------------



/*
cout << "\n{ " ;
for(int i=0;i<6;i++){
    cout << ycoord1[i] << "\t";
}cout << "}" << endl;
*/






//cout << "\n" << ydifference << " distinct y-coordinates found across x100A!" << endl;

for(int i=0;i<6;i++){               // dont care the unknown indexes, get every index+1, if index number later 0 is 0, ignore, maximum contain 6 distinct location
    cout << "jump index " << i+1 << " : " << xcoord1Jump[i] << endl;
}
cout << "\n";

for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            data[i][j] += dataA[i][j];
            data[i][j] += dataB[i][j];
        }
    }


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

void appendMatrix1(int arr[], int size, int xloc){
//x100A
//int ycoord1[6] = {0, 0, 0, 0, 0, 0};
//int ydifference = 1;
for(int i=0;i<size;i++){
    //ycoord1[indx]++;
    if(arr[i]==0){                                 //filter out (0, 0)
        cout << "zero!!" << endl;
    }
    else{
        int indx = int((round(static_cast<double>(arr[i])/100.0)-1));
        dataA[indx][xloc]++;
        }
    }
}

void appendMatrix2(int arr[], int size, int xloc){
//x100A
//int ycoord1[6] = {0, 0, 0, 0, 0, 0};
//int ydifference = 1;
for(int i=0;i<size;i++){
    //ycoord1[indx]++;
    if(arr[i]==0){                                 //filter out (0, 0)
        cout << "zero!!" << endl;
    }
    else{
        int indx = int((round(static_cast<double>(arr[i])/100.0)-1));
        dataB[indx][xloc]++;
        }
    }
}

void displayMatrix(){
    cout << "------------- M a t r i x   d a t a   f o r   r a w 1 -----------------------\n" << endl;
    cout << "\tR1\tR2\tR3\tR4\tR5\tNS" << endl;
    for(int j=0;j<6;j++){
        if(j<4){
            cout << "D\t";
        }
        else{cout << "R\t";}
        for(int i=0;i<6;i++){
            cout << dataA[j][i] << "\t";
        }
        cout << "\n";
    }
    cout << "\n---------------------------------------------------------------------------\n";

    cout << "------------- M a t r i x   d a t a   f o r   r a w 2 -----------------------\n" << endl;
    cout << "\tR1\tR2\tR3\tR4\tR5\tNS" << endl;
    for(int j=0;j<6;j++){
        if(j<4){
            cout << "D\t";
        }
        else{cout << "R\t";}
        for(int i=0;i<6;i++){
            cout << dataB[j][i] << "\t";
        }
        cout << "\n";
    }
    cout << "\n---------------------------------------------------------------------------\n";

    cout << "------------- F i n a l   M a t r i x   D a t a -----------------------\n" << endl;
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




/*


for(int i=0;i<xcoord[0]+1;i++){
    x100A[i] = data1[i][1];
}
for(int i=0;i<xcoord[1]+1;i++){
    x200A[i] = data1[i+1+xcoord[0]][1];
}
for(int i=0;i<xcoord[2]+1;i++){
    x300A[i] = data1[i+1+xcoord[0]+xcoord[1]][1];
}
for(int i=0;i<xcoord[3]+1;i++){
    x400A[i] = data1[i+1+xcoord[0]+xcoord[1]+xcoord[2]][1];
}
for(int i=0;i<xcoord[4]+1;i++){
    x500A[i] = data1[i+1+xcoord[0]+xcoord[1]+xcoord[2]+xcoord[3]][1];
}
for(int i=0;i<xcoord[5];i++){
    x600A[i] = data1[i+1+xcoord[0]+xcoord[1]+xcoord[2]+xcoord[3]+xcoord[4]][1];
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
