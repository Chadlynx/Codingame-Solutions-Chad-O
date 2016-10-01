#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/
int main()
{
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    int thorx;
    int thory;
    string directionX;
    string directionY;
    cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();
    thorx = initialTX; 
    thory = initialTY;
    // game loop
    while (1) {
        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remainingTurns; cin.ignore();
        directionX = "";
        directionY = "";
        if(thorx < lightX){
            directionX = "E";
            thorx++;
        }
        else if(thorx > lightX){
            directionX = "W";
            thorx--;
        }
        if(thory < lightY){
            directionY = "S";
            thory++;
        }
        else if(thory > lightY){
            directionY = "N";
            thory--;
        }
            
        
        // A single line providing the move to be made: N NE E SE S SW W or NW
        cerr << thorx << "," << thory << endl;
        cout << directionY << directionX << endl;
    }
}