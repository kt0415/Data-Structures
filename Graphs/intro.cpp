#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;       //n:no of nodes in the graph        m:no of edges of the graph
    cin>>n>>m;  

    //1: Adjacency Matrix Way.... O[N^2]
    // int mat[n+1][n+1] = {0};
    // for (int i = 0; i < m; i++)
    // {
    //     int a,b;
    //     cin>>a>>b;

    //     mat[a][b] = 1;
    //    // mat[b][a] = 1;      //if it is an undirected graph
    // }
    
    //2: Adjacency List Way ... O[2E] ... directed sathi O[E]
    vector<int>adj[n+1];

    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        // adj[v].push_back(u);    //if it is an undirected graph
    }
    
    
    
    return 0;
}