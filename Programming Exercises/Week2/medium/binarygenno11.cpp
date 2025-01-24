// Description
// Given an integer n, write a program that generates all binary sequences without consecutive 11 in a lexicographic order.
// Input
// Line 1: contains an integer n (1 <= n <= 20)
// Output
// Write binary sequences in a lexicographic order, each sequence in a line
// Example
// Input
// 3
// Output
// 000
// 001
// 010
// 100
// 101
#include <bits/stdc++.h>
using namespace std;
bool check(int n, int arr[])
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == 1 && arr[i - 1] == 1)
            return false;
    }
    return true;
}
void biniterate(int n, int arr[], int i)
{
    if (i == n && check(n, arr))
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[j];
        }
        cout << endl;
        return;
    }
    if (i > n)
    {
        return;
    }
    arr[i] = 0;
    biniterate(n, arr, i + 1);
    arr[i] = 1;
    biniterate(n, arr, i + 1);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
    }
    biniterate(n, arr, 0);
    return 0;
}