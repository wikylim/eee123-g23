#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){

    //raw data
    cout<<"raw1>> [(0, 0), (100, 98), (99, 99), (100, 99), (101, 99), (98, 100), (99, 100), (100, 100), (101, 100), (102, 100), (97, 101), (98, 101), (99, 101), (100, 101), (101, 101), (102, 101), (103, 101), (98, 102), (99, 102), (100, 102), (101, 102), (102, 102), (99, 103), (100, 103), (101, 103), (100, 104), (600, 197), (599, 198), (600, 198), (601, 198), (598, 199), (599, 199), (600, 199), (601, 199), (602, 199), (597, 200), (598, 200), (599, 200), (600, 200), (601, 200), (602, 200), (603, 200), (598, 201), (599, 201), (600, 201), (601, 201), (602, 201), (599, 202), (600, 202), (601, 202), (600, 203), (300, 297), (299, 298), (300, 298), (301, 298), (298, 299), (299, 299), (300, 299), (301, 299), (302, 299), (297, 300), (298, 300), (299, 300), (300, 300), (301, 300), (302, 300), (303, 300), (298, 301), (299, 301), (300, 301), (301, 301), (302, 301), (299, 302), (300, 302), (301, 302), (300, 303), (400, 497), (399, 498), (400, 498), (401, 498), (398, 499), (399, 499), (400, 499), (401, 499), (402, 499), (397, 500), (398, 500), (399, 500), (400, 500), (401, 500), (402, 500), (403, 500), (398, 501), (399, 501), (400, 501), (401, 501), (402, 501), (399, 502), (400, 502), (401, 502), (400, 503)]"<<endl;
    cout<<"raw2>> [(0, 0)] "<<endl;
    cout<<"raw3>> [(0, 0)]"<<endl;
    cout<<endl;

    //sorted data
    cout<<"sort..."<<endl;
    cout<<"sorted_data1: ";
    cout<<"{";
    int sorted_data1[3]={1,2,3};
    for(int i=0;i<3;i++){
        std::cout<<sorted_data1[i];
        if (i<2){
            cout<<", ";
        }
    }
        cout<<"}"<<endl;
        
        cout<<"sorted_data2: ";
        cout<<"{";
    int sorted_data2[3]={4,5,6};
    for(int i=0;i<3;i++){
        std::cout<<sorted_data2[i];
        if (i<2){
            cout<<", ";
        }
    }
        cout<<"}"<<endl;
    cout<<"sorted_data3: ";
    cout<<"{";
    int sorted_data3[3]={7,8,9};
    for(int i=0;i<3;i++){
        std::cout<<sorted_data3[i];
        if (i<2){
            cout<<", ";
        }
    }
        cout<<"}"<<endl;
        cout<<endl;

//final data
    cout<<"final_data: "<<endl;
    cout<<"{"<<endl;
    int final_data[6][6]=  {{1, 2, 3, 4, 5, 6},
                            {7, 8, 9, 10, 11, 12},
                            {13, 14, 15, 16, 17, 18},
                            {19, 20, 21, 22, 23, 24},
                            {25, 26, 27, 28, 29, 30},
                            {31, 32, 33, 34, 35, 36}};
                            
    for (int i = 0; i < 6; i++) {
    cout << "   {";
    for (int j = 0; j < 6; j++) {
        cout << setw(2)<<final_data[i][j];
        if (j < 5) {
            cout << ", ";
        }
    }
    cout << "}";
    if (i < 5) {
        cout << ","<<endl;
    }
    }
    cout<<endl;
    cout << "}" << endl;
        cout<<endl;
    
//matrix form
    cout<<"final_data(in matrix form): "<<endl;
    for(int i=0;i<6;i++) {
        for(int j=0;j<6;j++) {
            cout<<setw(4)<<final_data[i][j]<<" ";
        }
    cout<<endl;
    }


//outputfile

    ofstream outputfile ("output.txt");
    if(outputfile.is_open()){
          //raw data
    outputfile<<"raw1>> [(0, 0), (100, 98), (99, 99), (100, 99), (101, 99), (98, 100), (99, 100), (100, 100), (101, 100), (102, 100), (97, 101), (98, 101), (99, 101), (100, 101), (101, 101), (102, 101), (103, 101), (98, 102), (99, 102), (100, 102), (101, 102), (102, 102), (99, 103), (100, 103), (101, 103), (100, 104), (600, 197), (599, 198), (600, 198), (601, 198), (598, 199), (599, 199), (600, 199), (601, 199), (602, 199), (597, 200), (598, 200), (599, 200), (600, 200), (601, 200), (602, 200), (603, 200), (598, 201), (599, 201), (600, 201), (601, 201), (602, 201), (599, 202), (600, 202), (601, 202), (600, 203), (300, 297), (299, 298), (300, 298), (301, 298), (298, 299), (299, 299), (300, 299), (301, 299), (302, 299), (297, 300), (298, 300), (299, 300), (300, 300), (301, 300), (302, 300), (303, 300), (298, 301), (299, 301), (300, 301), (301, 301), (302, 301), (299, 302), (300, 302), (301, 302), (300, 303), (400, 497), (399, 498), (400, 498), (401, 498), (398, 499), (399, 499), (400, 499), (401, 499), (402, 499), (397, 500), (398, 500), (399, 500), (400, 500), (401, 500), (402, 500), (403, 500), (398, 501), (399, 501), (400, 501), (401, 501), (402, 501), (399, 502), (400, 502), (401, 502), (400, 503)]"<<endl;
    outputfile<<"raw2>> "<<endl;
    outputfile<<"raw3>> "<<endl;
    outputfile<<endl;

    //sorted data
    outputfile<<"sort..."<<endl;
    outputfile<<"sorted_data1: ";
    outputfile<<"{";
    int sorted_data1[3]={1,2,3};
    for(int i=0;i<3;i++){
        outputfile<<sorted_data1[i];
        if (i<2) {
            outputfile<<", ";
        }
    }
        outputfile<<"}";
        outputfile<<endl;
        

        outputfile<<"sorted_data2: ";
        outputfile<<"{";
    int sorted_data2[3]={4,5,6};
    for(int i=0;i<3;i++){
        outputfile<<sorted_data2[i];
        if (i<2) {
            outputfile<<", ";
        }
    }
    outputfile<<"}";

        outputfile<<endl;
    outputfile<<"sorted_data3: ";
    outputfile<<"{";
    int sorted_data3[3]={7,8,9};
    for(int i=0;i<3;i++){
        outputfile<<sorted_data3[i];   
        if (i<2) {
            outputfile<<", ";
        }
    }
    outputfile<<"}";

    outputfile<<endl;
    outputfile<<endl;

    outputfile<<"___________________________________Final output____________________________________________________"<<endl;
    //final data
    outputfile<<"final_data: "<<endl;
    outputfile<<"{"<<endl;
    int final_data[6][6]=  {{1, 2, 3, 4, 5, 6},
                            {7, 8, 9, 10, 11, 12},
                            {13, 14, 15, 16, 17, 18},
                            {19, 20, 21, 22, 23, 24},
                            {25, 26, 27, 28, 29, 30},
                            {31, 32, 33, 34, 35, 36}};

    for (int i = 0; i < 6; i++) {
    outputfile << " {";
    for (int j = 0; j < 6; j++) {
        outputfile << setw(2)<<final_data[i][j];
        if (j < 5) {
            outputfile << ", ";
        }
    }
    outputfile << "}";
    if (i < 5) {
        outputfile << ","<<endl;
    
    }
    }
    outputfile<<endl;
    outputfile << "}"<<endl;
    outputfile<<endl;

    outputfile<<"final_data(in matrix form):"<<endl;
    outputfile<<"_____________________________"<<endl;
    outputfile<<"  R1   R2   R3   R4   R5   R6  "<<endl;
    
    for(int i=0;i<6;i++) {
        for(int j=0;j<6;j++) {
            outputfile<<setw(4)<<final_data[i][j]<<" ";
        }
    outputfile<<endl;
    }
    outputfile<<"_____________________________"<<endl;

//close output.txt
    outputfile.close();
    }else{
        cerr<<"unable to open file for writing."<<endl;
    }
    
    return 0;

}
