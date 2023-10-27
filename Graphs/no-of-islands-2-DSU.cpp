#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet
{
public:
    vector<int> parent, size;
    DisjointSet(int n)
    { // resizing our size and parent vectors to n+1 size in case of 1 based indexing and n size in case of 0 based indexing
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int node) // to find the ultimate parent of the given node using path compression and recursion
    {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]); // path compression done here
    }

    void unionBySize(int u, int v)
    {
        int pu = findParent(u); // ultimate parent of u
        int pv = findParent(v); // ultimate parent of v

        if (pu == pv)
            return; // if they have the same ultimate parent, dont do anything, simply return

        if (size[pu] < size[pv]) // if the pu's component is smaller than that of pv
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }

        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) 
    {
        DisjointSet ds(n*m);   //every cell to be a part of disjoint set
        int vis[n][m];  //visited array to mark all the visited nodes
        memset(vis,0, sizeof vis);  //marking all nodes as unvisited in the initial configuration
        vector<int>ans; //to mark current no of island for each query
        int cnt = 0;
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        for(auto it: operators)
        {
            int row = it[0];
            int col = it[1];
            if(vis[row][col] == 1)  //if already visited, it means the query is repeated. No change in cnt then
            {
                ans.push_back(cnt);
                continue;
            }
            //but if it isnt visited
            vis[row][col] = 1;  //we mark it as visited
            cnt++;  //and initially treat it as an individual island
            
            //check its neighbours..
            for(int i=0; i<4; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)  //condition for valid cell
                {
                    if(vis[nrow][ncol] == 1)    //checking if neighbour is actually an island
                    {
                        int nodenum = row * m + col;    
                        int adjnodenum =  nrow * m + ncol;
                        if(ds.findParent(nodenum) != ds.findParent(adjnodenum)) //comparing their node numbers to check whether they have the same ultimate parent or not
                        {   //if they dont have the same ultimate parent, reduce the count and connect them
                            cnt--;
                            ds.unionBySize(nodenum,adjnodenum);
                        }
                        
                    }
                }
            }
            
            ans.push_back(cnt);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}
