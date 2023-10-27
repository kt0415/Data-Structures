#include <bits/stdc++.h>
using namespace std;

#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

void dfs(int node, vector<int>adjlist[], int vis[], vector<int>&ls)
{
    vis[node] = 1;
    ls.push_back(node);

    for(auto it: adjlist[node])
    {
        if(!vis[it])
            dfs(it,adjlist,vis,ls);
    }
}

int numberofprovinces(vector<vector<int>>adj, int V)
{
    int vis[V] = {0};   //created a visited array to check all elements of graph have been visited/not
    vector<int>ls;      //a vector to store the dfs traversal
    int cnt = 0;        //cnt variable to count the number of provinces

    //converting our given adjacency matrix to adjacency list
    vector<int>adjlist[V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if(adj[i][j] == 1 && i!=j)
            {
                adjlist[i].push_back(j);
                adjlist[j].push_back(i);
            }
        } 
    }

    for (int i = 0; i < V; i++)
    {
        if(!vis[i])
        {
            dfs(i,adjlist,vis,ls);
            cnt++;
        }
    }
    
    return cnt;
}


int main()
{
    int t; cin>>t;
    while(t--)
    {
        fastIO;
        int V, x;
        cin>>V;

        vector<vector<int>>adj;

        for(int i=0; i<V; i++)
        {
            vector<int>temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }

            adj.push_back(temp);
        }

        int ans = numberofprovinces(adj,V);
        cout<<ans<<endl;
    }
    return 0;
}