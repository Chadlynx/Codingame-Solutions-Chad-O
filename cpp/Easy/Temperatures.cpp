#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();

    string temps; // the n temperatures expressed as integers ranging from -273 to 5526
    getline(cin, temps);
    
    //Integer array to store temperature values
    int * inttemps;
    inttemps = new int [n];
    
    //Parsing string values to int array.
    int i = 0;
    int min;
    stringstream stream(temps);
    while(stream)  {
        int n;
        stream >> n;
        inttemps[i++] = n;
    }
    //Determining value closest to 0.
    for(int i = 0; i<=n; i++)  {
        int absoluteval = abs(inttemps[i]);
        if(absoluteval == abs(min) && inttemps[i] > 0)  //Deals with the case of two min negative numbers.
                min = absoluteval;
        if(absoluteval < abs(min))
            min = inttemps[i];
    }

    cerr << "min = " << min << endl;
    
    cout << min << endl;
    //delete [] inttemps;
}
