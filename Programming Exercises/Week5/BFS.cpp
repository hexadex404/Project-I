// Description
// Given undirected graph G = (V,E) in which V = {1, 2, ..., n} is the set of nodes, and E is the set of m edges.
// Write a program that computes the sequence of nodes visited using a BFS algorithm (the nodes are considered in a lexicographic order)

// Input
// Line 1: contains 2 integers n and m which are the number of nodes and the number of edges
// Line i+1 (i = 1, ..., m): contains 2 positive integers u and v which are the end points of the ith edge

// Output
// Write the sequence of nodes visited by a BFS procedure (nodes a are separated by a SPACE character)
// Example

// Input
// 16 16
// 2 4
// 1 3
// 3 4
// 5 6
// 1 2
// 3 5
// 2 3
// 7 2
// 6 9
// 9 10
// 4 10
// 5 11
// 8 12
// 12 14
// 13 15
// 13 16
// Output
// 1 2 3 4 7 5 10 6 11 9 8 12 14 13 15 16

#include <bits/stdc++.h>
using namespace std;

typedef struct Graph
{
    int V;
    int E;
    int **adj;
} Graph;

Graph *create_graph(int V, int E)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->adj = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        graph->adj[i] = (int *)calloc(V, sizeof(int));
    return graph;
}

void add_edge(Graph *graph, int u, int v)
{
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1;
}

void BFS(Graph *graph, int start, int visited[])
{
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u + 1 << " ";
        for (int i = 0; i < graph->V; i++)
        {
            if (graph->adj[u][i] && !visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph *graph = create_graph(n, m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        add_edge(graph, u - 1, v - 1);
    }
    int visited[] = {0};
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            BFS(graph, i, visited);
    }
    return 0;
}