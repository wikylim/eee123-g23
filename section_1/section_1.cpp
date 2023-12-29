//welcome...
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(){
char line;
string temp = "okay";
//tuple<int , int> data;
int number, i=0, j=0, k=0, repeat =0, raw1[1000][2], change;

string filePath = "C:\\cpp\\aaaaa\\set 2\\raw1.txt"; 
ifstream input_file(filePath);
if (!input_file.is_open()) {
    cerr << "Could not open the file - '" << filePath << "'" << endl;
    return EXIT_FAILURE;
}
//input data
input_file >> temp;
input_file >> line;

while (input_file >> line){  
    if (input_file >> number){    
        raw1 [i][j] = number;

        if (j == 0){
            j+=1; 
        }
        else {
            j-=1;
            i++;
            input_file >> temp;
            repeat ++;
        }
    }
}
input_file.close();

//print collected data
cout << "[";
for (i=0 ; i < repeat ; i++){
    j=0;
    cout << "(" <<raw1 [i][j] << " , " ;
    while (j == 0){
        j = 1;
        cout << raw1 [i][j] << ") " ; 
        
    }
}
cout << "]";

return 0;
}