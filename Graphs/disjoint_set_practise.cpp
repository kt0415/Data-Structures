#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    vector<int>rank,parent,size;

public:
    DisjointSet(int n)
    {//resizing our rank and parent vectors to n+1 size in case of 1 based indexing and n size in case of 0 based indexing
        rank.resize(n+1,0);     
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

    void unionByRank(int u, int v)
    {
        //get the ultimate parents of u and v and store them in pu and pv respectively
        int pu = findParent(u); //ultimate parent of u
        int pv = findParent(v); //ultimate parent of v

        if(pu == pv)    return; //if they have the same ultimate parent, dont do anything, simply return

        if(rank[pu]<rank[pv])   //if v's ultimate parent's rank is more than the u's ultimate parent's rank, then pu goes and gets attached to pv
        {
            parent[pu] = pv;
        }

        else if(rank[pu]>rank[pv])   //if u's ultimate parent's rank is more than the v's ultimate parent's rank, then pv goes and gets attached to pu
        {
            parent[pv] = pu;
        }

        else    //both have the ultimate parents with equal ranks
        {
            parent[pu] = pv;    //attach any to any, did attach pu to pv here
            rank[pv]++;     //hence pv cha rank vadhla!!
        }
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

int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    //if 3 and 7 have same parent or not ... 
    if(ds.findParent(3) == ds.findParent(7))
        cout<<"They have the same parent \n";
    else
        cout<<"They belong to different graph components\n";

    ds.unionBySize(3,7);
    //after connecting, check again
    if(ds.findParent(3) == ds.findParent(7))
        cout<<"They have the same parent \n";
    else
        cout<<"They belong to different graph components\n";
        
    return 0;
}