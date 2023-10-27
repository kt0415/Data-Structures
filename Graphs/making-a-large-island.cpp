//{ Driver Code Starts
// Initial Template for C++

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
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        //step1:- Connect components
        for(int i = 0; i < n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 0) continue;
                
                for(int k=0; k<4; k++)
                {
                    int nrow = i + drow[k];
                    int ncol = j + dcol[k];
                    
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1)
                    {
                        int nodenum = i*n + j;
                        int adjnodenum = nrow*n + ncol;
                        
                        ds.unionBySize(nodenum,adjnodenum);
                    }
                }
            }
        }
        //now our disjoint set is formed as per the required initial configuration
        
        //step2 ; Brute Force
        int mx = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1) continue;
                set<int>comp;
                for(int k=0; k<4; k++)
                {
                    int nrow = i + drow[k];
                    int ncol = j + dcol[k];
                    
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n)
                    {
                        if(grid[nrow][ncol] == 1)
                        {
                            int adjnodenum = nrow*n + ncol;
                            comp.insert(ds.findParent(adjnodenum));
                        }
                    }    
                }
                
                int sizetot = 0;
                for(auto it: comp)
                {
                    sizetot += ds.size[it];
                }
                
                mx = max(mx,sizetot+1);
            }
        }
        
        for(int cell=0; cell<n*n; cell++)
        {
            mx = max(mx,ds.size[ds.findParent(cell)]);
        }
        
        return mx;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends