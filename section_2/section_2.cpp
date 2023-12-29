//welcome...
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    char line;
    string temp = "okay";
    int number, i=0, j=0, k=0, repeat =0, raw1[1000][2], change;
    //sort for y coordinate
    cout << "\n\n Sorted y coordinate\n";
    for (i = 0; i < repeat; i++) {
        for (k = i + 1; k < repeat; k++) {
            if (raw1[i][1] >= raw1[k][1]) {
                change = raw1[i][1];
                raw1[i][1] = raw1[k][1];
                raw1[k][1] = change;
            }
        }
    }
    for (i=0 ; i < repeat ; i++){
        j=0;
        cout << "(" <<raw1 [i][j] << " , " ;
        while (j == 0){
            j = 1;
            cout << raw1 [i][j] << ") " ; 
    }
}


return 0;
}