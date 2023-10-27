#include <bits/stdc++.h>
using namespace std;

// void dfs(int node, vector<int>adj[], int vis[], stack<int>&st)
// {
//     vis[node] = 1;

//     for(auto it: adj[node])
//     {
//         if(!vis[it])
//         {
//             dfs(it,adj,vis,st);
//         }
//     }

//     st.push(node);
// }

void TopoSort(int node, vector<pair<int,int>>adj[], int vis[], stack<int>&st)
{
    vis[node] = 1;
    for(auto it: adj[node])
    {
        int x = it.first;
        if(!vis[x])
        {
            TopoSort(x,adj,vis,st);
        }
    }

    st.push(node);
}


vector<int>shortestpath(int N, int M, vector<vector<int>>&edges)
{
    //create an adjacency list
    vector<pair<int,int>>adj[N];    //u -> v with weight w, v and w as pairs taken
    for(int i=0; i<M; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v,wt}); 
    }

    //get the topological sort
    int vis[N] = {0};
    stack<int>st;
    TopoSort(0,adj,vis,st);//as source is 0, else we had to substitute node as src{source node}

    //now the distances are to be considered
    vector<int>dist(N);
    for(int i=1; i<N; i++)  dist[i] = INT_MAX;
    dist[0] = 0;

    while(!st.empty())
    {
        int u = st.top();
        st.pop();

        for(auto it: adj[u])
        {
            int v = it.first;
            int wt = it.second;

            dist[v] = min(dist[v],dist[u]+wt);
        }
    }

    for(int i=0; i<N; i++)
    {
        if(dist[i] == 1e9)
            dist[i] = -1;
    }

    return dist;
}


int main()
{

    return 0;
}