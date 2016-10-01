#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;


int main()
{
    //Alphabet String
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ?";
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    string T;
    getline(cin, T);
    
    vector<string> letters;
    for (int i = 0; i < H; i++) {
        string ROW;
        getline(cin, ROW);
        letters.push_back(ROW);
    }

    vector<string> printthis(H);
    for(int j = 0; j < T.length(); j++)  {
    //Find the index of the letter to print.
        char upper = toupper(T[j]);
        int index = alpha.find(upper);
        if (index < 0 || index > 25)
            index = 26;
        for(int i = 0; i<H; i++)  {
            string line = letters[i].substr(index*L,L);
            printthis[i] += line;
        }
    }
    
    for(int i = 0; i<H ; i++)
        cout << printthis[i] << endl;
        

}
