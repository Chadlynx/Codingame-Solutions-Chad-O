#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N;
    cin >> N; cin.ignore();
    vector<int> horses(N);
    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        horses[i] = Pi;
    }
    
    sort(horses.begin(),horses.begin() + N);
    
    int diff;
    int mindiff = INT_MAX;
    for(int i = 1; i < N; i++)  {
        diff = horses[i] - horses[i-1];
        if(diff < mindiff)
            mindiff = diff;
    }

    cout << mindiff << endl;
}
