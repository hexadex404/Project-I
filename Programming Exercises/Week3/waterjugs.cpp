#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int pour(int fc, int tc, int d)
{
    int fr = fc, to = 0, step = 1;
    while (fr != d && to != d)
    {
        int temp = min(fr, tc - to);
        to += temp;
        fr -= temp;
        step++;
        if (fr == d || to == d)
            break;
        if (fr == 0)
        {
            fr = fc;
            step++;
        }
        if (to == tc)
        {
            to = 0;
            step++;
        }
    }
    return step;
}
int minSteps(int m, int n, int d)
{
    if (m > n)
        swap(m, n);
    if (d > n)
        return -1;
    if ((d % gcd(n, m)) != 0)
        return -1;
    return min(pour(n, m, d), pour(m, n, d));
}

int main()
{
    int m, n, d;
    cin >> m >> n >> d;
    cout << minSteps(m, n, d) << endl;
    return 0;
}