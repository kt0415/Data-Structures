#include <bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    void dfs(int node, vector<int>adj[], int vis[],stack<int>&st)
    {
        vis[node] = 1;  //in the dfs, initially the node is marked as visited

        for(auto it: adj[node]) //then its adjacency list is checked.. for every element in adjacency list which isnt previously visited, a dfs call is made
        {
            if(!vis[it])
            {
                dfs(it,adj,vis,st);
            }
        }
        
        st.push(node);  //after the dfs is complete, the element is inserted in the stack
    }
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
        int vis[V] = {0};
        stack<int>st;
        for(int i=0; i<V; i++)  //for multiple components
        {
            if(!vis[i])
            {
                dfs(i,adj,vis,st);  //if the element is not visited, its dfs gets called
            }
        }
        //our stack has all the elements in the topological order
        vector<int>ans;     //so we start inserting them into our ans vector
        while(!st.empty())
        {
            int temp = st.top();
            st.pop();
            ans.push_back(temp);
        }
        
        return ans; //and at the end, return our topological sequence
	}
};

int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

// //      BFS..   Kahn's Algorithm
// 	public:
// 	//Function to return list containing vertices in Topological order. 
// 	vector<int> topoSort(int V, vector<int> adj[]) 
// 	{
// 	    vector<int>ans;
// 	    queue<int>q;
// 	    //indegree array construction..
// 	    int indegree[V] = {0};
// 	    for(int i=0; i<V; i++)
// 	    {
// 	        for(auto it: adj[i])
// 	        {
// 	            indegree[it]++;
// 	        }
// 	    }
	    
// 	    //check for nodes with indegree 0
// 	    for(int i=0; i<V; i++)
// 	    {
// 	        if(indegree[i] == 0)
// 	        {
// 	            q.push(i);
// 	        }
// 	    }
	    
// 	    //khelo BFS
// 	    while(!q.empty())
// 	    {
// 	        int node = q.front();
// 	        q.pop();
// 	        ans.push_back(node);
	        
// 	        //node is into your ans{toposort}.. please remove it from the indegree
// 	        for(auto it: adj[node])
// 	        {
// 	            indegree[it] --;
// 	            if(indegree[it]==0)
// 	            {
// 	                q.push(it);
// 	            }
// 	        }
// 	    }
	   
// 	   return ans; 
// 	}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}