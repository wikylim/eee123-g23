#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>


#define cout std::cout
#define endl std::endl
const std::size_t MAX_SIZE = 1;
void appendElement(int arr[], std::size_t& size, int newValue);

template <std::size_t Rows, std::size_t Cols>
int getIndex(int(&array)[Rows][Cols]){
    return Rows;
}

//---------------------------------- V a r i a b l e s ---------------------------------
int row = 6;
int col = 7;
int data[6][7] = {{0, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0, 0},
                  };
int threshold = 30;
//--------------------------------------------------------------------------------------

int main() {

int raw1[][2] = {{0, 0}, {100, 98}, {99, 99}, {100, 99}, {101, 99}, {98, 100}, {99, 100}, {100, 100}, {101, 100}, {102, 100}, {97, 101}, {98, 101}, {99, 101}, {100, 101}, {101, 101}, {102, 101}, {103, 101}, {98, 102}, {99, 102}, {100, 102}, {101, 102}, {102, 102}, {99, 103}, {100, 103}, {101, 103}, {100, 104}, {600, 197}, {599, 198}, {600, 198}, {601, 198}, {598, 199}, {599, 199}, {600, 199}, {601, 199}, {602, 199}, {597, 200}, {598, 200}, {599, 200}, {600, 200}, {601, 200}, {602, 200}, {603, 200}, {598, 201}, {599, 201}, {600, 201}, {601, 201}, {602, 201}, {599, 202}, {600, 202}, {601, 202}, {600, 203}, {300, 297}, {299, 298}, {300, 298}, {301, 298}, {298, 299}, {299, 299}, {300, 299}, {301, 299}, {302, 299}, {297, 300}, {298, 300}, {299, 300}, {300, 300}, {301, 300}, {302, 300}, {303, 300}, {298, 301}, {299, 301}, {300, 301}, {301, 301}, {302, 301}, {299, 302}, {300, 302}, {301, 302}, {300, 303}, {400, 497}, {399, 498}, {400, 498}, {401, 498}, {398, 499}, {399, 499}, {400, 499}, {401, 499}, {402, 499}, {397, 500}, {398, 500}, {399, 500}, {400, 500}, {401, 500}, {402, 500}, {403, 500}, {398, 501}, {399, 501}, {400, 501}, {401, 501}, {402, 501}, {399, 502}, {400, 502}, {401, 502}, {400, 503}};
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

for (int i=0;i<getIndex(raw1);i++){
    for(int j=0;j<2;j++){
        data1[i][j] = raw1[i][j];
    }
}
for (int i=0;i<getIndex(raw2);i++){
    for(int j=0;j<2;j++){
        data2[i][j] = raw2[i][j];
    }
}
for (int i=0;i<getIndex(raw3);i++){
    for(int j=0;j<2;j++){
        data3[i][j] = raw3[i][j];
    }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------- s o r t   b y   x - c o o r d i n a t e   i n   a s c e n d i n g   o r d e r ---------------------------------
//std::sort(&data1[0][0], &data1[0][0] + data1_Index * 2, [](int a, int b) {return a < b;});
//std::sort(&data2[0][0], &data2[0][0] + data2_Index * 2, [](int a, int b) {return a < b;});
//std::sort(&data3[0][0], &data3[0][0] + data3_Index * 2, [](int a, int b) {return a < b;});

for(int i=0;i<data1_Index;i++){
    for(int i=0;i<data1_Index;i++){
        if(data1[i+1][0]<data1[i][0]){
            int tempdata[2];
            tempdata[0]=data1[i][0];
            tempdata[1]=data1[i][1];

            data1[i][0]=data1[i+1][0];
            data1[i][1]=data1[i+1][1];
    
            data1[i+1][0]=tempdata[0];
            data1[i+1][1]=tempdata[1];
        }
}}
for(int i=0;i<data2_Index;i++){
    for(int i=0;i<data2_Index;i++){
        if(data2[i+1][0]<data2[i][0]){
            int tempdata[2];
            tempdata[0]=data2[i][0];
            tempdata[1]=data2[i][1];

            data2[i][0]=data2[i+1][0];
            data2[i][1]=data2[i+1][1];
    
            data2[i+1][0]=tempdata[0];
            data2[i+1][1]=tempdata[1];
        }
}}
for(int i=0;i<data3_Index;i++){
    for(int i=0;i<data3_Index;i++){
        if(data3[i+1][0]<data3[i][0]){
            int tempdata[2];
            tempdata[0]=data3[i][0];
            tempdata[1]=data3[i][1];

            data3[i][0]=data3[i+1][0];
            data3[i][1]=data3[i+1][1];
    
            data3[i+1][0]=tempdata[0];
            data3[i+1][1]=tempdata[1];    
    }
}}
cout << "\n";
//-----------------------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------ D i s p l a y   d a t a   a r r a y -------------------------------------------
for(int i=0;i<getIndex(raw1);i++){
    for(int j=0;j<2;j++){
        cout << data1[i][j] << " ";
    }
    cout << "\n";
}
cout << "\n data2" << endl;
for(int i=0;i<getIndex(raw2);i++){
    for(int j=0;j<2;j++){
        cout << data2[i][j] << " ";
    }
    cout << "\n";
}
cout << "\n data3" << endl;
for(int i=0;i<getIndex(raw3);i++){
    for(int j=0;j<2;j++){
        cout << data3[i][j] << " ";
    }
    cout << "\n";
}cout << "\n";
//-----------------------------------------------------------------------------------------------------------------------------------------------------


int difference = 0;
int xcoord[6] = {0, 0, 0, 0, 0, 0};
int indexjump[6];

for(int i=1;i<data1_Index+1;i++){
    int indx;
    static int placeIndex = 0;                  // static int, when running in loop, it will only declare once and not reset the value
    static int placeIndex2 = 0;
    if(data1[i][0]==0){cout << "zero!!" << endl;} //filter out (0, 0)
    else if(data1[i+1][0]-data1[i][0]<threshold){
        indx = round(static_cast<double>(data1[i][0])/100.0)-1;
        //cout << indx << endl;
        xcoord[indx]++;
        placeIndex = indx;
    }
    else{
        xcoord[placeIndex]++;
        difference++;
        indexjump[placeIndex2] = i;
        placeIndex2++;
    }
}
/*
int x100[xcoord[0]];
int x200[xcoord[1]];
int x300[xcoord[2]];
int x400[xcoord[3]];
int x500[xcoord[4]];
int x600[xcoord[5]];

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

cout << x100[0] << endl;
cout << "data1 y-coord: ";
cout << "\nx100: ";
for(int i=0;i<xcoord[0];i++){
    cout << x100[i] << " ";
}
cout << "\nx200: ";
for(int i=0;i<xcoord[1];i++){
    cout << x200[i] << " ";
}
cout << "\nx300: ";
for(int i=0;i<xcoord[2];i++){
    cout << x300[i] << " ";
}
cout << "\nx400: ";
for(int i=0;i<xcoord[3];i++){
    cout << x400[i] << " ";
}
cout << "\nx500: ";
for(int i=0;i<xcoord[4];i++){
    cout << x500[i] << " ";
}
cout << "\nx600: ";
for(int i=0;i<xcoord[5];i++){
    cout << x600[i] << " ";
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

cout << "\n{ " ;
for(int i=0;i<6;i++){
    cout << xcoord[i] << " ";
}cout << "}" ;
    cout << "\n" << difference << " x-coordinates found!" << endl;

for(int i=0;i<6;i++){
    cout << indexjump[i] << " ";
}


    return 0;
}


void appendElement(int arr[], std::size_t& size, int newValue) {
    if (size < MAX_SIZE) {
        arr[size] = newValue;
        ++size;
    } else {
        cout << "Array is full. Cannot append.\n";
    }
}