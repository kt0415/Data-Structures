//Tarjan's Algorithm mhntat hyala

#include <bits/stdc++.h>
using namespace std;

int t = 1;

void dfs(int node, int parent, vector<int>adj[], vector<int>&visited, vector<int>&tin, vector<int>&low, vector<vector<int>>&bridges)
{
    visited[node] = 1;
    tin[node]=low[node] = t;
    t++;

    for(auto it: adj[node])
    {
        if(it == parent)    continue;

        if(!visited[it])
        {
            dfs(it,node,adj,visited,tin,low,bridges);
            low[node] = min(low[node],low[it]);

            if(low[it]>tin[node])
            {
                bridges.push_back({node,it});
            }

            else
                low[node] = min(low[node],low[it]);
        }
    }
}

vector<vector<int>> allbridges(int n, vector<vector<int>>&connections)
{
    //step1: graph formation
    vector<int>adj[n];
    for(auto it: connections)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    //graph formation done

    //step2: pre-requisite items declaration
    vector<int>visited(n,0);    //a visited array to mark the nodes that have been visited, initialised to 0
    vector<int>tin(n,0); //time of insertion
    vector<int>low(n,0);    //lowest time of insertion
    vector<vector<int>>bridges;    //to store our bridges

    //step3: make a dfs call
    dfs(0,-1,adj,visited,tin,low,bridges);

    return bridges;
}

int main()
{

    return 0;
}