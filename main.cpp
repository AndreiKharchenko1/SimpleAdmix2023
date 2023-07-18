#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <stdexcept>
#include <sstream>
#include <math.h>

 using namespace std;



void admix();
 int main(){
 admix();
 }

void admix(){
    string File;
    int Target, source1, source2, source3;
cout << "Enter File Name: ";
cin >> File;
cout << "\n Enter Population to be modeled (integer, column number) : ";
cin >> Target;
cout << "\n Enter Source 1 (integer, column number) : ";
cin >> source1;
cout << "\n Enter Source 2 (integer, column number) : ";
cin >> source2;
cout << "\n Enter Source 3 (integer, column number) : ";
cin >> source3;

    ifstream file(File.c_str());
    if (!file) {
        cout << "Unable to open file" << endl;

        main();
    }
float S1dist = 0; float S2dist = 0; float S3dist = 0; float S1S2 = 0; float S1S3 = 0; float S2S3 = 0;
    string line;
    while (getline(file, line)) {
       std::stringstream ss(line);
        float target; float value;
        int columnCount = 0;
        float S1, S2, S3;

        while (ss >> value) {

            columnCount++;
            if (columnCount == Target){
                target = value;} else
            if (columnCount == source1){
                S1 = value;
            } else
            if (columnCount == source2){
                S2 = value;
            } else
            if (columnCount == source3){
                S3 = value;
            }
        }

        S1dist = S1dist + (target-S1)*(target-S1);
        S2dist = S2dist + (target-S2)*(target-S2);
        S3dist = S3dist + (target-S3)*(target-S3);
        S1S2 = S1S2 + (S1-S2)*(S1-S2);
        S1S3 = S1S3 + (S1-S3)*(S1-S3);
        S2S3 = S2S3 + (S2-S3)*(S2-S3);
    }
    cout << " S1dist = " << S1dist;
    cout << " S2dist = " << S2dist;
    cout << " S3dist = " << S3dist;
    cout << " S1S2 = " << S1S2;
    cout << " S1S3 = " << S1S3;
    cout << " S2S3 = " << S2S3;
    cout << "\n VahaduoCoords: ";
    cout << "\n Source1," << 0 << "," << S1S2 << "," << S1S3 ;
    cout << "\n Source2," << S1S2 << ","<< 0 << ","<< S2S3;
    cout << "\n Source3," << S1S3 << "," << S2S3 << "," << 0;
    cout << "\n Target," << S1dist << "," << S2dist << "," << S3dist;
main();
}
