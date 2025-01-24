// Description
// Given a directed graph G = (V,E) in which V = {1,2,...,n) is the set of nodes. Each arc (u,v) has a non-negative weight w(u,v). Given two nodes s and t of G. Find the shortest path from s to t on G.
// Input
// Line 1: contains two integers n and m which are the number of nodes and the number of arcs of G (1 <= n <= 100000)
// Line i + 1(i = 1,2,...,m): contains 3 integers u, v, w in which w is the weight of arc(u,v) (0 <= w <= 100000)
// Line m+2: contains two integers s and t
// Output
// Write the weight of the shortest path found or write -1 if no path from s to t was found
// Example
// Input
// 5 7
// 2 5 87
// 1 2 97
// 4 5 78
// 3 1 72
// 1 4 19
// 2 3 63
// 5 1 18
// 1 5

// Output
// 97

#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

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
    int n, m, u, v, w, s, t;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        addEdge(adj, u - 1, v - 1, w);
    }
    cin >> s >> t;
    shortestPath(adj, s - 1, t - 1);
    return 0;
}