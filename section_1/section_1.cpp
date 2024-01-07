#include <iostream>
#include <fstream>
using namespace std;

void readTextFiles(const string& folderPath, int set) {
    char line;
    string temp ; 
    int number, i=0, j=0, k=0, repeat =0, raw[3][5000][2], change;

    ifstream input_file(folderPath);
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


int main() {
    string filePath, newfilepath;
    
    do {
        cout << "\nPlease enter reference folder location.\n\nEg : \"C:\\This PC\\EEE\\Reference\\Set 5\"\nFile location : ";
        getline(cin,filePath);
        newfilepath = filePath + "\\raw1.txt";
        ifstream input_file(newfilepath);

        //to check either file location is valid or not
        if(input_file.is_open()){
            break;
        }
        else{
            cerr << "\nFolder don't have text file in it - '" << filePath << "'\nPlease try again.\n";
        }
    }while (true);

    //set the array number for each raw data
    for (int set = 0 ; set < 3 ; set++){
        if (set == 0){
            newfilepath = filePath + "\\raw1.txt";
        }
        else if (set == 1){
            newfilepath = filePath + "\\raw2.txt";
        }
        else{
            newfilepath = filePath + "\\raw3.txt";
        }
        //read and save data in array form
        readTextFiles(newfilepath, set);
    }
    return 0;
}
