// Description
// Given an undirected graph G = (V,E). Write a program to check if G is a Hamiltonian graph.
// Input
// Line 1: a positive integer T (number of graphs)
// Subsequent lines are information about T graphs, each has the following format:
// Line 1: n and m (number of nodes and edges)
// Line i+1 (i = 1, 2, ..., m): u and v : two end points of the ith edge
// Output
// In the i
// th
//  line, write 1 if the corresponding is a Hamiltonian graph, and write 0, otherwise
// Example
// Input
// 2
// 5 5
// 1 2
// 1 3
// 2 4
// 2 5
// 3 5
// 7 13
// 1 3
// 1 5
// 1 7
// 2 4
// 2 5
// 2 6
// 3 4
// 3 5
// 3 7
// 4 6
// 4 7
// 5 7
// 6 7

// Output
// 0
// 1

// Idea: Use backtracking to find a Hamiltonian cycle. The idea is similar to the backtracking algorithm for finding a Hamiltonian path. The only difference is that we need to check if the last vertex in the path is connected to the first vertex in the path.

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

void remove_edge(Graph *graph, int u, int v)
{
    graph->adj[u][v] = 0;
    graph->adj[v][u] = 0;
}

bool is_safe(Graph *graph, int *path, int pos, int v)
{
    if (graph->adj[path[pos - 1]][v] == 0)
        return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    return true;
}

bool hamiltonian_cycle(Graph *graph, int *path, int pos)
{
    if (pos == graph->V)
    {
        if (graph->adj[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }
    for (int v = 1; v < graph->V; v++)
    {
        if (is_safe(graph, path, pos, v))
        {
            path[pos] = v;
            if (hamiltonian_cycle(graph, path, pos + 1) == true)
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;

        Graph *graph = create_graph(n, m);
        int u, v;
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            add_edge(graph, u - 1, v - 1);
        }

        int *path = (int *)calloc(n, sizeof(int));
        path[0] = 0;
        for (int i = 1; i < n; i++)
            path[i] = -1;

        if (hamiltonian_cycle(graph, path, 1) == true)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}