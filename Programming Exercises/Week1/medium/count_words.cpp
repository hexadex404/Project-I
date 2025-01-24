// Description
// Given a Text, write a prorgam to count the number Q of words (ignore characters SPACE, TAB, LineBreak) of this Text

// Input
// The Text

// Output
// Write the number Q of words

// Example
// Input
// Hanoi University Of Science and Technology
// School of Information and Communication Technology

// Output
// 12
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int count = 0;
    while (1){
        if (cin.peek() == '\n')
        {
            cin.ignore();
            continue;
        }
        else if (cin.eof())
        {
            break;
        }
        string s;
        getline(cin, s);
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                count++;
            }
        }
        cout << count + 1;
        return 0;
    }
}