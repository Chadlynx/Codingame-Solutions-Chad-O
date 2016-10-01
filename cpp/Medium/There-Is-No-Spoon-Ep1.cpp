#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/
int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    bool nodes[width][height];
    
    for (int i = 0; i < height; i++) {
        string line; // width characters, each either 0 or .
        getline(cin, line);
        for(int j = 0; j < width; j++)
            nodes[j][i] = line[j] == '0';
    }
    string empty = "-1 -1 ";
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++)  {
            bool foundx = 0;
            bool foundy = 0;
            //Do shit if there's a node at this coordinate
            if(nodes[x][y])  {
                cout << x << " " << y << " ";
                
            //Check nodes to the right
            for(int z = x+1; z < width; z++)  {
                if(nodes[z][y] && z < width && foundx == 0){
                    cout << z << " " << y << " ";
                    foundx = 1;
                }
            }
            if(!foundx)
                cout << empty;
                
            //Check nodes below
            for(int z = y+1; z < height; z++)  {
                if(nodes[x][z] && z < height && foundy == 0)  {
                    cout << x << " " << z << " ";
                    foundy = 1;
                }
            }
            if(!foundy)
                cout << empty;
                
            cout << endl;
            }            
        }
    }
}   
