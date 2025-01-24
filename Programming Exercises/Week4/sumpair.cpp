// Description
// Cho dãy a1, a2, ..., an trong đó các phần tử đôi một khác nhau và 1 giá trị nguyên dương M. Hãy đếm số Q các cặp (i,j) sao cho 1 <= i < j <= n và ai + aj = M.

// Dữ liệu
// Dòng 1: ghi n và M (1 <= n, M <= 1000000)
// Dòng 2: ghi a1, a2, ..., an
// Kết quả
// Ghi ra giá trị Q
// Ví dụ
// Dữ liệu
// 5 6
// 5 2 1 4 3
// Kết quả
// 2

#include <bits/stdc++.h>
using namespace std;

int main(){
    int count = 0;
    int n,m;
    cin >> n >> m;
    int a[n];
    map<int,int> map;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        map[a[i]] = i;
    }
    for (int i = 0; i < n; i++){
        if (map.find(m-a[i]) != map.end()) count++;
    }
    cout << count/2;
}