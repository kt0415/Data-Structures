#include <bits/stdc++.h>
using namespace std;

#define FastIO          \
    ios_base::sync_with_stdio(0);   \
    cin.tie(0);             \
    cout.tie(0);

vector<vector<int>> nearest(vector<vector<int>>&grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>>vis(n, vector<int>(m,0));    //a n*m matrix to check whether the cell has been visited or not... initially all cells hold 0
    vector<vector<int>>dist(n,vector<int>(m,0));    //answer matrix to store distance to nearest zeroes
   queue<pair<pair<int,int>,int>>q;     //a queue to store the row and column pair coordinates alongside the nearest 0 distance
   
   //traversal through the entire matrix to find the already 0s in the given grid
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(grid[i][j]==0)
            {
                vis[i][j] = 1;      //marking them as visited in visited matrix
                q.push({{i,j},0});  //inserting their {{row,col},dist} in the queueDS
            }
        }
    }

    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};

    while(!q.empty())
    {
        auto it = q.front();        //storing the front element of the queue into the temporary variable iterator it
        int row = it.first.first;   //storing the row value into the temporary variable row using the it iterator
        int col = it.first.second;  //storing the column value into the temporary variable col using the it iterator
        int d = it.second;  //storing the nearest 0 distance value into the temporary variable d using the it iterator
    
        dist[row][col] = d;     //assigning the nearest 0 distance of the front element of queue to its position in the distance matrix
    
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0)
            {
                vis[nrow][ncol] = 1;
                q.push({{nrow,ncol},d+1});
            }
        }
    }

    return dist;
}

int main()
{
    FastIO;
    int t; cin>>t; 
    while(t--)
    {
        int n,m; 
        cin>>n>>m;

        vector<vector<int>>grid(n,vector<int>(m,-1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin>>grid[i][j];
            }
        }

        vector<vector<int>>ans = nearest(grid);

        for(auto it: ans)
        {
            for(auto pr: it)
            {
                cout<<pr<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}