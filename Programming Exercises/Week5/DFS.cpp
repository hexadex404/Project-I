// Description
// Given a undirected graph =(V,E) in which V = {1,2,..,n} is the set of nodes. Write a program that visit nodes of G by a DFS (consider a lexicorgraphic order of nodes).
// Input
// Line 1: contains 2 integers n and m (1 <= n,m <= 100000)
// Line i+1: contains u and v which are two end-points of the ith edge

// Output
// Sequence of nodes visited by DFS
// Example
// Input
// 7 12
// 1 2
// 1 3
// 2 3
// 2 4
// 2 7
// 3 5
// 3 7
// 4 5
// 4 6
// 4 7
// 5 6
// 5 7
// Output
// 1 2 3 5 4 6 7

#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

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

void DFS(Graph *graph, int start, int visited[])
{
    visited[start] = 1;
    printf("%d ", start + 1);
    for (int i = 0; i < graph->V; i++)
    {
        if (graph->adj[start][i] && !visited[i])
            DFS(graph, i, visited);
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
    int visited[MAX] = {0};
    DFS(graph, 0, visited);
    return 0;
}
