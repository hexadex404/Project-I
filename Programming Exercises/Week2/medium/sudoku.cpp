#include <bits/stdc++.h>
using namespace std;

const int SIZE = 9;

// bool checkRow(array<array<int, SIZE>, SIZE> &board, int row, int num)
// {
//     for (int i = 0; i < SIZE; i++)
//     {
//         if (board[row][i] == num)
//         {
//             return false;
//         }
//     }
//     return true;
// }
// bool checkCol(array<array<int, SIZE>, SIZE> &board, int col, int num)
// {
//     for (int i = 0; i < SIZE; i++)
//     {
//         if (board[i][col] == num)
//         {
//             return false;
//         }
//     }
//     return true;
// }
// bool checkBox(array<array<int, SIZE>, SIZE> &board, int row, int col, int num)
// {
//     int boxx = row / 3;
//     int boxy = col / 3;
//     for(int i = 0; i <3; i++)
//     for(int j = 0; j <3; j++)
//     {
//         if(board[boxx*3+i][boxy*3+j] == num)
//         {
//             return false;
//         }
//     }
//     return true;
// }

// int solver(array<array<int, SIZE>, SIZE> &board, int count)
// {
//     for (int i = 0; i < SIZE; i++)
//     {
//         for (int j = 0; j < SIZE; j++)
//         {
//             if (board[i][j] == 0)
//             {
//                 for (int n = 1; n <= SIZE && count < 2; n++)
//                 {
//                     if (checkRow(board, i, n) && checkCol(board, j, n) && checkBox(board, i, j, n))
//                     {
//                         board[i][j] = n;
//                         int cache = solver(board, count);
//                         if (cache > count)
//                         {
//                             count = cache;
//                             for (int k = 0; k < SIZE; k++)
//                             {
//                                 for (int l = 0; l < SIZE; l++)
//                                 {
//                                     if (board[k][l] != 0)
//                                     {
//                                         array<array<int, SIZE>, SIZE> board2;
//                                         board2[k][l] = board[k][l];
//                                     }
//                                 }
//                             }
//                             board[i][j] = 0;
//                         }
//                         else
//                         {
//                             board[i][j] = 0;
//                         }
//                     }
//                 }
//                 return count;
//             }
//         }
//     }
//     return count + 1;
// }
// int main()
// {
//     array<array<int, SIZE>, SIZE> board;
//     int count = 0;
//     for (int i = 0; i < SIZE; i++)
//     {
//         for (int j = 0; j < SIZE; j++)
//         {
//             cin >> board[i][j];
//             if (board[i][j] != 0)
//             {
//                 count++;
//             }
//         }
//     }
//     solver(board, count);
//     cout << count;
//     return 0;
// }

bool checkRC(array<array<int, SIZE>, SIZE> &board, int row, int col, int num)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (board[row][i] == num || board[i][col] == num)
        {
            return false;
        }
    }
    return true;
}

bool checkBox(array<array<int, SIZE>, SIZE> &board, int row, int col, int num)
{
    int boxx = row / 3;
    int boxy = col / 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            if (board[boxx * 3 + i][boxy * 3 + j] == num)
            {
                return false;
            }
        }
    return true;
}

bool isSafe(array<array<int, SIZE>, SIZE> &board, int row, int col, int num)
{
    return checkRC(board, row, col, num) && checkBox(board, row, col, num);
}

bool getRC(array<array<int, SIZE>, SIZE> &board, int &row, int &col)
{
    for (row = 0; row < SIZE; row++)
    {
        for (col = 0; col < SIZE; col++)
        {
            if (board[row][col] == 0)
            {
                return true;
            }
        }
    }
    return false;
}
int countSol(array<array<int, SIZE>, SIZE> &board, int ans)
{
    int row, col;
    if (getRC(board, row, col))
    {
        for (int num = 1; num <= SIZE; num++)
        {
            if (isSafe(board, row, col, num))
            {
                board[row][col] = num;
                int prev = ans;
                ans = countSol(board, ans);
                board[row][col] = 0;
            }
        }
    }
}

void solve(array<array<int, SIZE>, SIZE> &board)
{
    int a = 0;
    int ans = countSol(board, a);
    cout << ans;
}

int main()
{
    array<array<int, SIZE>, SIZE> board;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cin >> board[i][j];
        }
    }
    solve(board);
    return 0;
}
