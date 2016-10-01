#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);
    
    cerr << MESSAGE << endl;
    //Convert Message to Binary
    string binarystring = "";
    
    for(int i = 0; i < MESSAGE.length(); i++)
        binarystring += bitset<7>(MESSAGE[i]).to_string();
    
    string answerstring = "";
    string temp = "";
    int current; //Dummy value to hold 0 or 1.
    
    //Iterate over each character in binary string.
    for(string::iterator it = binarystring.begin(); it != binarystring.end(); ++it)  {
        int is_zero = (* it == '0'); // check if current value is 0 or 1.
        
        //Same series, append another zero
        if(is_zero == current)
            temp += "0";
        
        //New series
        else  {
            current = is_zero;  //Update value for series
            
            if(answerstring.length() > 0) //Add a space if it isn't the first series
                answerstring += " ";
                
            answerstring += temp;
            
            if(current)
                temp = "00 0";
            else
                temp = "0 0";
        }
    }
    answerstring += " " + temp; //Add last character
    
    //Display answer
    cout << answerstring << endl;
}
