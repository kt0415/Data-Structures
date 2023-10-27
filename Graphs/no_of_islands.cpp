#include <bits/stdc++.h>
using namespace std;

#define fastIO  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0); \
    cout.tie(0); \

void bfs(int row, int col, vector<vector<int>>vis, vector<vector<char>>&grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vis[row][col] = 1;  //marking the row,col piece as visited
    queue<pair<int,int>>q;
    q.push({row,col});  //pushing the piece in the stack

    while(!q.empty())   
    {
        //getting the element from the queue and using 2 variables r and c to access its row and col no
        int r = q.front().first;    
        int c = q.front().second;
        q.pop();

        //traverse in the neighbours and mark them as visited
        for (int drow = -1; drow <=1; drow++)
        {
            for(int dcol= -1; dcol<=1; dcol++)
            {
                int nrow = r + drow;    //neighbouring row
                int ncol = c + dcol;        //neighbouring column

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == '1')
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
}

int no_of_islands(vector<vector<char>>grid)
{
    int n = grid.size();    //no_of_rows
    int m = grid[0].size();     //no_of_columns

    int cnt = 0;    //to count no of islands
    
    vector<vector<int>>vis(n, vector<int>(m,0));    //visited matrix initially all values = 0
    
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if(!vis[row][col] && grid[row][col] == '1') //piece should be unvisited and it should be a land piece
            {
                cnt++;                      
                bfs(row,col,vis,grid);      //bfs call
            }
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
        int n,m; 
        cin>>n>>m;

        vector<vector<char>> grid(n, vector<char>(m,'#'));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin>>grid[i][j];   
            }
        }
        
        int ans = no_of_islands(grid);
        cout<<ans<<endl;
    }
    return 0;
}