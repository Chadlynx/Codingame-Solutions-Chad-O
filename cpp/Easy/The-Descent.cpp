#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{

    // game loop
    while (1) {
        int hmax = 0;
        int imax = 0;
        for (int i = 0; i < 8; i++) {
            int mountainH; // represents the height of one mountain, from 9 to 0.
            cin >> mountainH; cin.ignore();
            if (mountainH > hmax)  {
                hmax = mountainH;
                imax = i;   
            }
        }

            

        // Write an action using cout. DON'T FORGET THE "<< endl"
        
        // To debug: cerr << "Debug messages..." << endl;

        cout << imax << endl; // The number of the mountain to fire on.
    }
}