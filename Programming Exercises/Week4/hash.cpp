// Description
// Given a string s[1…k] which is a sequence of characters taken from {‘a’, . . ., ‘z’}. Given a positive integer m, the hash code of s is defined by the formula:
// H(s) =  (s[1]*256
// k-1
//  + s[2]*256
// k-2
//  + . . . + s[k]*256
// 0 
// ) mod m  (the contant integer m is a parameter)
// Given a sequence of strings k1, k2, …, kn, compute the corresponding hash codes
// Input
// Line 1: n and m (1 <= n,m <= 100000)
// Line i+1 (i = 1,2,…,n): contains the string ki (the length of each string is less than or equal to 200)
// Output
// Each line contains the corresponding hash code of n given strings
// Example
// Input
// 4 1000
// a
// ab
// abc
// abcd
// Output
// 97
// 930
// 179
// 924

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        int sum = 0;
        for (int j = 0; j < s.length(); j++){
            sum = (sum*256 + s[j])%m;

        }
        cout << sum%m << endl;
    }
    return 0;
}