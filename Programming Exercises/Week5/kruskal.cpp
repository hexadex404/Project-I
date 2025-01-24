// Description
// Given a undirected connected graph G=(V,E) where V={1,…,N}. Each edge (u,v)∈E(u,v)∈E has weight w(u,v)w(u,v). Compute minimum spanning tree of G.
// Input
// Line 1: N and M (1≤N,M≤10^5) in which NN is the number of nodes and MM is the number of edges.
// Line i+1 (i=1,…,M): contains 3 positive integers u, v, and w where w is the weight of edge (u,v)
// Output
// Write the weight of the minimum spanning tree found.
// Example
// Input
// 5 8
// 1 2 1
// 1 3 4
// 1 5 1
// 2 4 2
// 2 5 1
// 3 4 3
// 3 5 3
// 4 5 2
// Output
// 7

#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

typedef struct Edge
{
    int u;
    int v;
    int w;
} Edge;

typedef struct Graph
{
    int V;
    int E;
    Edge *edge;
} Graph;

Graph *create_graph(int V, int E)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (Edge *)malloc(E * sizeof(Edge));
    return graph;
}

typedef struct Subset
{
    int parent;
    int rank;
} Subset;

int find(Subset *subsets, int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(Subset *subsets, int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int myComp(const void *a, const void *b)
{
    Edge *a1 = (Edge *)a;
    Edge *b1 = (Edge *)b;
    return a1->w > b1->w;
}

int kruskal(Graph *graph)
{
    int V = graph->V;
    Edge result[V];
    int e = 0;
    int i = 0;
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
    Subset *subsets = (Subset *)malloc(V * sizeof(Subset));
    for (int v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while (e < V - 1 && i < graph->E)
    {
        Edge next_edge = graph->edge[i++];
        int x = find(subsets, next_edge.u);
        int y = find(subsets, next_edge.v);
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    int min_cost = 0;
    for (i = 0; i < e; i++)
        min_cost += result[i].w;
    return min_cost;
}

int main()
{
    int N, M;
    cin >> N >> M;
    Graph *graph = create_graph(N, M);
    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph->edge[i].u = u - 1;
        graph->edge[i].v = v - 1;
        graph->edge[i].w = w;
    }
    cout << kruskal(graph);
    return 0;
}
