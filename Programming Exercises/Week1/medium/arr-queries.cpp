// Description
// Given a sequence of integers a1, a2, ..., an. Perform a sequence of queries over this sequence including:
// find-max: return the maximum element of the given sequence
// find-min: return the minimum element of the given sequence
// sum: return the sum of the elements of the given sequence
// find-max-segment i j: return the maximum element of the subsequence from index i to index j (i <= j)

// Input
// The first block contains the information about the given sequence with the following format:
// Line 1: contains a positive integer n (1 <= n <= 10000)
// Line 2: contains n integers a1, a2, ..., an (-1000 <= ai <= 1000)
// The first block is terminated by a character *
// The second block contains a sequence of queries defined above, each query is in a line. The second block is terminated a 3 characters ***

// Output
// Write the result of each query in a corresponding line

// Example
// Input
// 5
// 1 4 3 2 5
// *
// find-max
// find-min
// find-max-segment 1 3
// find-max-segment 2 5
// sum
// ***

// Output
// 5
// 1
// 4
// 5
// 15

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    string block_termi;
    cin >> block_termi;
    while (true)
    {
        vector<string> query;
        string s;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> s)
        {
            query.push_back(s);
        }
        if (query == vector<string>{"***"})
        {
            break;
        }
        while (query.size() == 1)
        {
            if (query[0] == "find-max")
            {
                cout << *max_element(arr, arr + n) << endl;
                break;
            }
            else if (query[0] == "find-min")
            {
                cout << *min_element(arr, arr + n) << endl;
                break;
            }
            else if (query[0] == "sum")
            {
                cout << accumulate(arr, arr + n, 0) << endl;
                break;
            }
            else
            {
                break;
            }
        }
        while (query.size() == 3)
        {
            if (query[0] == "find-max-segment")
            {
                cout << *max_element(arr + stoi(query[1]) - 1, arr + stoi(query[2])) << endl;
                break;
            }
            else if (query[0] == "find-min-segment")
            {
                cout << *min_element(arr + stoi(query[1]) - 1, arr + stoi(query[2])) << endl;
                break;
            }
        }
    }
    return 0;
}