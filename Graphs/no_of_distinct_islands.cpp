#include <bits/stdc++.h>
using namespace std;

#define FastIO                          \
    ios_base::sync_with_stdio(0);       \
    cin.tie(0);                              \
    cout.tie(0);

void dfs(int row, int col, vector<vector<int>>&vis, vector<vector<int>>&grid, vector<pair<int,int>>&vec, int baserow, int basecol)
{
    int n = grid.size();
    int m = grid[0].size();

    vis[row][col] = 1;
    vec.push_back({row-baserow, col-basecol});

    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
        {
            dfs(nrow,ncol,vis,grid,vec,baserow,basecol);
        }
    }

}

int countDistinctIslands(vector<vector<int>>&grid)
{
    //getting the dimensions of the given grid
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0)); //creating a visited array to mark the visited cells
    set<vector<pair<int,int>>>s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(!vis[i][j] && grid[i][j]==1)
            {
                vector<pair<int,int>>vec;
                dfs(i,j,vis,grid,vec,i,j);
                s.insert(vec);
            }
        }  
    }
    
    int ans = s.size();
    return ans;
}

int main() 
{
    FastIO;
    int t;
    cin >> t;
    while (t--) 
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        
        int ans = countDistinctIslands(grid);
        cout<<ans<<endl;
    }
}