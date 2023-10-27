#include <bits/stdc++.h>
using namespace std;

#define FastIO          \
    ios_base::sync_with_stdio(0);       \
    cin.tie(0);                     \
    cout.tie(0);  

//BFS .. using Kahn's Algorithm
    //  // Function to detect cycle in a directed graph.
    // bool isCyclic(int V, vector<int> adj[])
    // {
    //     int cnt = 0;
	//     queue<int>q;
	//     //indegree array construction..
	//     int indegree[V] = {0};
	//     for(int i=0; i<V; i++)
	//     {
	//         for(auto it: adj[i])
	//         {
	//             indegree[it]++;
	//         }
	//     }
	    
	//     //check for nodes with indegree 0
	//     for(int i=0; i<V; i++)
	//     {
	//         if(indegree[i] == 0)
	//         {
	//             q.push(i);
	//         }
	//     }
	    
	//     //khelo BFS
	//     while(!q.empty())
	//     {
	//         int node = q.front();
	//         q.pop();
	//         cnt++;
	        
	//         //node is into your ans{toposort}.. please remove it from the indegree
	//         for(auto it: adj[node])
	//         {
	//             indegree[it] --;
	//             if(indegree[it]==0)
	//             {
	//                 q.push(it);
	//             }
	//         }
	//     }
	   
    //     if(cnt == V)
    //         return false;
    //     return true;
    // }    

//DFS ....
bool dfscheck(int node, vector<int>adj[], int vis[], int pathvis[])
{
    vis[node] = 1; 
    pathvis[node] = 1;

    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            if(dfscheck(it,adj,vis,pathvis)==true)  
                return true;

            else if(vis[it] && pathvis[it])
                return true;
        }
    }

    pathvis[node] = 0;
    return false;
}

bool detectcycle(int V, vector<int>adj[])
{
    //declaring the visited and path visited arrays initially with all elements of both arrays 0
    int vis[V] = {0};
    int pathvis[V] = {0};

    for (int i = 0; i < V; i++)
    {
        if(!vis[i])
        {
            if(dfscheck(i,adj,vis,pathvis)==true)
                return true;
        }
    }

    return false;
    
}

int main()
{
    FastIO;

    int t; cin>>t;
    while(t--)
    {
        int V, E;
        cin>>V>>E;

        vector<int>adj[V];

        for (int i = 0; i < E; i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }

        bool ans = detectcycle(V,adj);

        if(ans == true)
        {
            cout<<"YES, a cycle is present in the given directed graph!"<<endl;
        }
        
        else
        {
            cout<<"There does not exist any cycle in the given directed graph"<<endl;
        }

    }

    return 0;
}