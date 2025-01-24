// Problem: All pair shortest paths
// Description
// Given a directed graph G = (V, E) in which V = {1, 2, ..., n} is the set of nodes, and w(u,v) is the weight (length) of the arc(u,v). Compute d(u,v) - the length of the shortest path from u to v in G, for all u,v in V.
// Input
// Line 1: contains 2 positive integers n and m (1 <= n,m <= 10000)
// Line i+1 (i = 1, 2, ..., m): contains 3 positive integers u, v, w in which w is the weight of the arc (u,v) (1 <= w <= 1000)
// Output
// Line i (i = 1, 2, ..., n): wirte the ith row of the matrix d (if there is not any path from node i to node j, then d(i,j) = -1)
// Example
// Input
// 4 9
// 1 2 9
// 1 3 7
// 1 4 2
// 2 1 1
// 2 4 5
// 3 4 6
// 3 2 2
// 4 1 5
// 4 2 8
// Output
// 0 9 7 2
// 1 0 8 3
// 3 2 0 5
// 5 8 12 0

#include <bits/stdc++.h>
using namespace std;

#define MAX 10000

void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
}

void shortestPath(vector<pair<int, int>> adj[], int s, int t)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(MAX, INT_MAX);
    pq.push(make_pair(0, s));
    dist[s] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    if (dist[t] == INT_MAX)
        cout << -1;
    else
        cout << dist[t];
}

int main()
{
    int n, m, u, v, w;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        addEdge(adj, u - 1, v - 1, w);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cout << 0 << " ";
            else
            {
                shortestPath(adj, i, j);
                cout << " ";
            }
        }
        cout << "\n";
    }
}
