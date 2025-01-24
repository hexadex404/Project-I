// Description
// The data about bank transactions consists of a sequence of transactions: the information of each transaction has the following format:
//                                                                     <from_account>   <to_account>   <money>   <time_point>   <atm>
// In which:
// •	<from_account>: the account from which money is transferred (which is a string of length from 6 to 20 )
// •	<to_account>: the account which receives money in the transaction (which is a string of length from 6 to 20)
// •	<money>: amount of money transferred in the transaction (which is an integer from 1 to 10000)
// •	<time_point>: the time point at which the transaction is performed, it is a string under the format HH:MM:SS  (hour: minute: second)
// •	<atm>: the code of the ATM where the transaction is taken (a string of length from 3 to 10)
// Example: T00112233445 T001234002 2000 08:36:25 BIDV (at the ATM BIDV, account T00112233445 transfers 2000$ to account T001234002 at time point 08:36:25 (08 hour, 36 minutes, 25 seconds)
// A transaction cycle of length k starting from account a1 is defined to be a sequence of distinct account a1, a2, …, ak  in which there are transactions from account a1 to a2, from a2 to a3, …, from ak to a1.
// Write a program that process the following queries:
// ?number_transactions: compute the total number of transactions of the data
// ?total_money_transaction: compute the total amount of money of transactions
// ?list_sorted_accounts: compute the sequence of bank accounts (including sending and receiving accounts) appearing in the transaction (sorted in an increasing (alphabetical) order)
// ?total_money_transaction_from <account>: compute the total amount of money transferred from the account <account>
// ?inspect_cycle <account> k : return 1 if there is a transaction cycle of length k, starting from <account>, and return 0, otherwise
// Input (stdin)
// The input consists of 2 blocks of information: the data block and the query block
// •	The data block consists of lines:
// o	Each line contains the information about a transaction described above
// o	The data is terminated by a line containing #
// •	The query block consists of lines:
// o	Each line is a query described above
// o	The query block is terminated by a line containing #

// Output (stdout)
// •	Print to stdout (in each line) the result of each query described above

// Example
// Input
// T000010010 T000010020 1000 10:20:30 ATM1
// T000010010 T000010030 2000 10:02:30 ATM2
// T000010010 T000010040 1500 09:23:30 ATM1
// T000010020 T000010030 3000 08:20:31 ATM1
// T000010030 T000010010 4000 12:40:00 ATM2
// T000010040 T000010010 2000 10:30:00 ATM1
// T000010020 T000010040 3000 08:20:31 ATM1
// T000010040 T000010030 2000 11:30:00 ATM1
// T000010040 T000010030 1000 18:30:00 ATM1
// #
// ?number_transactions
// ?total_money_transaction
// ?list_sorted_accounts
// ?total_money_transaction_from T000010010
// ?inspect_cycle T000010010 3
// #
// Output
// 9
// 19500
// T000010010 T000010020 T000010030 T000010040
// 4500
// 1

#include <bits/stdc++.h>
using namespace std;

struct Transaction
{
    string from_account;
    string to_account;
    int money;
    string time_point;
    string atm;
};

vector<Transaction> transactions;
int total_money = 0;
map<string, int> total_from = {};
set<string> accounts = {};
map<string, int> bit_ly = {};
bool adj[50][50];

void preprocess()
{
    int i = 0;
    for (auto account : accounts)
    {
        bit_ly[account] = i;
        i++;
    }
    for (auto transaction : transactions)
    {
        adj[bit_ly[transaction.from_account]][bit_ly[transaction.to_account]] = 1;
    }
    return;
}

int bit_cnt(int x)
{
    int ret = 0;
    for (int i = 0; i < bit_ly.size(); i++)
        ret += (x & (1 << i)) > 0;
    return ret;
}

bool BIT(int x, int pos)
{
    return x & (1 << pos);
}

int bfs(string start, int k)
{
    int startPos = bit_ly[start];
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({-1, {bit_ly[start], 1 << bit_ly[start]}});
    while (!pq.empty())
    {
        pair<int, pair<int, int>> tmp = pq.top();
        pair<int, int> loc = tmp.second;
        pq.pop();
        // cout << tmp.first << " " << loc.first << "\n";
        if (-tmp.first > k)
        {
            if (bit_cnt(loc.second) == k)
                return 1;
            continue;
        }
        for (int i = 0; i < bit_ly.size(); i++)
        {
            if (i == loc.first)
                continue;
            if (adj[loc.first][i])
            {
                if (i == startPos && -tmp.first == k)
                    return 1;
                if (!BIT(loc.second, i))
                {
                    int new_loc = loc.second | (1 << i);
                    pq.push({tmp.first - 1, {i, new_loc}});
                }
            }
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    while (getline(cin, line))
    {
        if (line == "#")
            break;
        stringstream ss(line);
        Transaction transaction;
        ss >> transaction.from_account >> transaction.to_account >> transaction.money >> transaction.time_point >> transaction.atm;
        transactions.push_back(transaction);
    }
    for (auto transaction : transactions)
    {
        total_money += transaction.money;
        total_from[transaction.from_account] += transaction.money;
        accounts.insert(transaction.from_account);
        accounts.insert(transaction.to_account);
    }
    bool graphTime = 0;
    while (getline(cin, line))
    {
        if (line == "#")
            break;
        stringstream ss(line);
        string query;
        ss >> query;
        if (query == "?number_transactions")
        {
            cout << transactions.size() << "\n";
        }
        else if (query == "?total_money_transaction")
            cout << total_money << "\n";
        else if (query == "?list_sorted_accounts")
        {
            for (auto account : accounts)
            {
                cout << account << " ";
            }
            cout << "\n";
        }
        else if (query == "?total_money_transaction_from")
        {
            string account;
            ss >> account;
            cout << total_from[account] << "\n";
        }
        else if (query == "?inspect_cycle")
        {
            if (!graphTime)
                preprocess();
            graphTime = 1;
            string account;
            int k;
            ss >> account >> k;
            cout << bfs(account, k) << '\n';
        }
    }
    return 0;
}
