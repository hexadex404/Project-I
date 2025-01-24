// Description
// Cho dãy số nguyên A1, A2, . . . , An với mỗi số nguyên Ai kiểm tra xem có số Aj nào bằng Ai hay không với j<i.
// Input
// Dòng đầu chứa số n (1≤n≤100,000)
// Dòng hai chứa nn số nguyên A1, A2, ..., An (1≤Ai≤1000,000,000)
// Output
// Ghi ra n dòng, dòng thứ i in ra 1 nếu tồn tại Aj=Ai với j<i, ngược lại in ra 0.
// Example
// input
// 5
// 1 4 3 1 4
// output
// 0
// 0
// 0
// 1
// 1

#include <bits/stdc++.h>
using namespace std;

#define MAX 10e8

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (m[a[i]] == 1)
            cout << 1 << endl;
        else
        {
            m[a[i]] = 1;
            cout << 0 << endl;
        }
    }
    return 0;
}