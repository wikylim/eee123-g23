//welcome...
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outputFile("output.txt");
    if (!outputFile.is_open())
    {
        cerr << "Error opening output file." << endl;
        return 1;
    }
    
    //Display raw data in terminal
   cout << "Raw Data: " << endl;
   cout << "Data("<<set+1<<")" << endl;
   cout << "[";
   for (i = 0; i < repeat; i++){
       j=0;
       cout << "(" <<raw[set] [i][j] << " , " ;
       j = 1;
       cout << raw[set] [i][j] << ") " ; 
       }
   cout << "]" << endl;
 
   //Display process data (sort) in terminal
   cout << "Sort data:" << endl;
   for (i=0; i < repeat; i++){
       j = 0;
       cout << "(" <<raw[set] [i][j] << ", " ;
       j = 1;
       cout << raw1 [i][j] << ") " ; 
       }
   cout << raw[set] [i][j] << ") " << endl;

   cout << endl << "-----------------------------------------------------------------------------" << endl;

   //Display final array form in terminal
   cout << "Final array form:" << endl;
   for (int i = 0; i < rows_d; i++) {
       cout << "{" << (i + 1) << " ";
       for (int j = 0; j < cols; j++) {
           // Display 1, 2, or 3 based on which set has data at this position
           if (matrix1[i][j] > 0) {
               cout << setw(3) << 1 << ", ";
           }
           else if (matrix2[i][j] > 0) {
               cout << setw(3) << 2 << ", ";
           }
           else if (matrix3[i][j] > 0) {
               cout << setw(3) << 3 << ", ";
           }
           else {
               cout << setw(3) << 0 << ", ";
           }
        }
    cout << "}" << endl;
    }

    //Display final matrix forn in terminal
    cout << "Final matrix Form:" << endl;
    cout << "| |R1|R2|R3|R4|R5|R6|NS|" << endl;
    for (int i = 0; i < rows_d; i++) {
      cout << "|D| " << (i + 1) << endl;
      for (int j = 0; j < cols; j++) {
        // Display 1, 2, or 3 based on which set has data at this position
        if (matrix1[i][j] > 0) {
            cout << "1| ";
        }
        else if (matrix2[i][j] > 0) {
            cout << "2| ";
        }
        else if (matrix3[i][j] > 0) {
            cout << "3| ";
        }
        else {
            cout << "0| ";
        }
      }
    }

   //Display raw data in txt file
   outputFile << "Raw Data: " << endl;
   outputFile << "Data("<<set+1<<")" << endl;
   outputFile << "[";
   for (int i = 0; i < repeat; i++){
       j=0;
       outputFile << "(" <<raw[set] [i][j] << " , " ;
       j = 1;
       outputFile << raw[set] [i][j] << ") " ; 
       }
   outputFile << "]" << endl;
 
   //Display process data (sort) in txt file
   outputFile << "Sort data:" << endl;
   for (int i=0; i < repeat; i++){
       j = 0;
       outputFile << "(" <<raw[set] [i][j] << ", " ;
       j = 1;
       outputFile << raw1[i][j] << ") " ; 
       }
   outputFile << raw[set] [i][j] << ") " << endl;

   outputFile << endl << "-----------------------------------------------------------------------------" << endl;

   //Display final array form in txt file
   outputFile << "Final array form:" << endl;
   for (int i = 0; i < rows_d; i++) {
       outputFile << "{" << (i + 1) << " ";
       for (int j = 0; j < cols; ++j) {
           // Display 1, 2, or 3 based on which set has data at this position
           if (matrix1[i][j] > 0) {
               outputFile << 1 << ", ";
           }
           else if (matrix2[i][j] > 0) {
               outputFile << 2 << ", ";
           }
           else if (matrix3[i][j] > 0) {
               outputFile << 3 << ", ";
           }
           else {
               outputFile << 0 << ", ";
           }
        }
    outputFile << "}" << endl;
    }

    //Display final matrix forn in txt file
    outputFile << "Final matrix Form:" << endl;
    outputFile << "| |R1|R2|R3|R4|R5|R6|NS|" << endl;
    for (int i = 0; i < rows_d; i++) {
    outputFile << "|D| " << (i + 1) << " ";
    for (int j = 0; j < cols; ++j) {
        // Display 1, 2, or 3 based on which set has data at this position
        if (matrix1[i][j] > 0) {
            outputFile << "1| ";
        }
        else if (matrix2[i][j] > 0) {
            outputFile << "2| ";
        }
        else if (matrix3[i][j] > 0) {
            outputFile << "3| ";
        }
        else {
            outputFile << "0| ";
        }
        }
    }

    // Close the file
    outputFile.close();

    return 0;
}