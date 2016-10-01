#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

//Convert string to lowercase for case insensitive string compare.
string lower(string str)  {
    for(int i = 0; i < str.size(); i++)
        str[i] = tolower(str[i]);
    return str;
}

int main()
{
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();

    map<string, string> table;
    for (int i = 0; i < N; i++) {
        string EXT; // file extension
        string MT; // MIME type.
        cin >> EXT >> MT; cin.ignore();
        EXT = lower(EXT);
        table[EXT] = MT;
    }
    
    string FNAMEext = "";
    for (int i = 0; i < Q; i++) {
        string FNAME; // One file name per line.
        getline(cin, FNAME);
        if(FNAME.find('.') != -1)  {
            FNAMEext = lower(FNAME.substr(FNAME.find_last_of(".")+1));
        }
        if(FNAME.find('.') != -1)  {
            map<string, string>:: iterator it = table.find(FNAMEext);
            if(it == table.end())
                cout << "UNKNOWN" << endl;
            else
                cout << it -> second << endl; 
        }else
            cout << "UNKNOWN" << endl;
    }
}
