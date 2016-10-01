#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cfloat>

using namespace std;

float distance(string lonA, string lonB, string latA, string latB)  {
    float x,y,d;
    float lona = stof(lonA), lonb = stof(lonB), lata = stof(latA), latb = stof(latB);
    
    x = (lonb - lona) * cos((latb + lata)/2);
    y = latb - lata;
    return sqrt(pow(x,2) + pow(y,2)) * 6371;
}

int main()
{
    string LON;
    cin >> LON; cin.ignore();
    string LAT;
    cin >> LAT; cin.ignore();
    LON[LON.find(',')] = '.';
    LAT[LAT.find(',')] = '.';
    
    int N;
    cin >> N; cin.ignore();
    float mindistance = FLT_MAX;
    float s = 0;
    string location = "";
    for (int i = 0; i < N; i++) {
        string DEFIB, DEFIBLONLAT, DEFIBLON, DEFIBLAT;
        getline(cin, DEFIB);
        DEFIB = DEFIB.substr(DEFIB.find_first_of(';') +1);  // Get rid of the number at the start

        DEFIBLONLAT = DEFIB.substr(DEFIB.substr(0,DEFIB.find_last_of(";")).find_last_of(";")+1);  // I didn't know how to find second last of lmao.

        DEFIBLON =  DEFIBLONLAT.substr(0,DEFIBLONLAT.find(";"));
        DEFIBLAT =  DEFIBLONLAT.substr(DEFIBLONLAT.find(";")+1);
        
        DEFIBLON[DEFIBLON.find(',')] = '.';
        DEFIBLAT[DEFIBLAT.find(',')] = '.';

        s = distance(LON, DEFIBLON, LAT, DEFIBLAT);  //  Distance between victim and defibrillator.
        
        if(s < mindistance)  {
            location = DEFIB.substr(0,DEFIB.find_first_of(';'));  // Get the location from the full string.
            mindistance = s;
        }
    }
    cout << location << endl;
}
