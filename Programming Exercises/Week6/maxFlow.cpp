// Description
// Given a network G = (V, E) which is a directed weighted graph. Node s is the source and node t is the target. c(u,v) is the capacity of the arc (u,v). Find the maximum flow on G.
// Input
// •Line 1: two positive integers N and M (1 <= N <= 10
// 4
// , 1 <= M <= 10
// 6
// )
// •Line 2: contains 2 positive integers s and t
// •Line i+2 (I = 1,. . ., M): contains two positive integers u and v which are endpoints of i
// th
//  arc
// Output
//   Write the value of the max-flow found
// Example
// Input
// 7 12
// 6 7
// 1 7 7
// 2 3 6
// 2 5 6
// 3 1 6
// 3 7 11
// 4 1 7
// 4 2 4
// 4 5 5
// 5 1 4
// 5 3 4
// 6 2 8
// 6 4 10
// Output
// 17

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

void add_edge(Graph *graph, int u, int v, int wt)
{
    graph->adj[u][v] = wt;
}

void remove_edge(Graph *graph, int u, int v)
{
    graph->adj[u][v] = 0;
}

bool bfs(Graph *graph, int s, int t, int parent[])
{
    bool visited[graph->V];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < graph->V; v++)
        {
            if (visited[v] == false && graph->adj[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return (visited[t] == true);
}

int max_flow(Graph *graph, int s, int t)
{
    int u, v;
    int max_flow = 0;
    int path_flow;
    int parent[graph->V];
    while (bfs(graph, s, t, parent))
    {
        path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, graph->adj[u][v]);
        }
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            graph->adj[u][v] -= path_flow;
            graph->adj[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main()
{
    int n, m, u, v, w, s, t;
    cin >> n >> m;
    cin >> s >> t;

    Graph *graph = create_graph(n, m);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        add_edge(graph, u - 1, v - 1, w);
    }

    cout << max_flow(graph, s - 1, t - 1);
    return 0;
}