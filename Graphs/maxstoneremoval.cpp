//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSet
{

public:
    vector<int>parent,size;
    DisjointSet(int n)
    {//resizing our size and parent vectors to n+1 size in case of 1 based indexing and n size in case of 0 based indexing
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int node)    //to find the ultimate parent of the given node using path compression and recursion
    {
        if(node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]); //path compression done here
    }

    void unionBySize(int u, int v)
    {
        int pu = findParent(u); //ultimate parent of u
        int pv = findParent(v); //ultimate parent of v

        if(pu == pv)    return; //if they have the same ultimate parent, dont do anything, simply return

        if(size[pu]<size[pv])   //if the pu's component is smaller than that of pv
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
    int maxRemove(vector<vector<int>>& stones, int n) 
    {
        int maxrow = 0;
        int maxcol = 0;
        
        for(auto it: stones)
        {
            maxrow = max(maxrow,it[0]);
            maxcol = max(maxcol,it[1]);
        }
        
        //we have got our total no of rows and columns
        DisjointSet ds(maxrow+maxcol+1);
        unordered_map<int,int>unique;   //if in a row there are multiple stones, we have to count it once only .. ek row ekda asa
        //combine the nodes in the Disjoint set using the given stones' coordinates
        for(auto it: stones)
        {
            int row = it[0];
            int col = it[1] + maxrow + 1;   //there are maxrow+1 rows
            
            ds.unionBySize(row,col);
            unique[row] = 1;
            unique[col] = 1;
        }
        
        int cnt = 0;
        for(auto it: unique)
        {
            if(ds.findParent(it.first) == it.first) //the node itself is the ultimate parent, then..
                cnt++;
        }
        
        int ans = n - cnt;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends