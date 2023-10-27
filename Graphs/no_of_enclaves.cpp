//solved using BFS traversal.....

#include <bits/stdc++.h>
using namespace std;

int numberofenclaves(vector<vector<int>>&grid)
{
    int n = grid.size();
    int m = grid[0].size();

    int vis[n][m] = {0};
    queue<pair<int,int>>q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(i == 0 || i == n-1 || j == 0 || j == m-1)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i,j});   
                    vis[i][j] = 1;
                }
            }
        } 
    }
    
    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};

    while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol] == 1)  
            {
                q.push({nrow,ncol});
                vis[nrow][ncol] = 1;
            } 
        }
    }
    
    int cnt = 0; 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(vis[i][j] == 0 && grid[i][j] == 1)
                cnt++;
        }
    }

    return cnt;
}

int main()
{
    vector<vector<int>>grid
    {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };
    
    int ans = numberofenclaves(grid);

    cout<<ans<<endl;
    return 0;
}

//DFS

// //{ Driver Code Starts
// // Initial Template for C++

// #include <bits/stdc++.h>
// using namespace std;


// // } Driver Code Ends
// // User function Template for C++

// class Solution {
//   private:
//     void dfs(int row, int col, vector<vector<int>>&vis, vector<vector<int>>&grid, int drow[], int dcol[])
//     {
//         vis[row][col] = 1;
//         int n = grid.size();
//         int m = grid[0].size();
        
//         for(int i=0; i<4; i++)
//         {
//             int nrow = row + drow[i];
//             int ncol = col + dcol[i];
            
//             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol] == 1)
//             {
//                 dfs(nrow,ncol,vis,grid,drow,dcol);
//             }
//         }
//     }
  
//   public:
//     int numberOfEnclaves(vector<vector<int>> &grid) 
//     {
//         int N = grid.size();
//         int M = grid[0].size();
        
//         vector<vector<int>>vis(N,vector<int>(M,0));
        
//         int drow[] = {-1,0,1,0};
//         int dcol[] = {0,1,0,-1};
        
//         //first and last column
//         for(int i=0; i<N; i++)
//         {
//             if(!vis[i][0] && grid[i][0] == 1)
//             {
//                 dfs(i,0,vis,grid,drow,dcol);
//             }
            
//             if(!vis[i][M-1] && grid[i][M-1] == 1)
//             {
//                 dfs(i,M-1,vis,grid,drow,dcol);
//             }
//         }
        
//         //first and last row
//         for(int j=0; j<M; j++)
//         {
//             if(!vis[0][j] && grid[0][j] == 1)
//             {
//                 dfs(0,j,vis,grid,drow,dcol);
//             }
            
//             if(!vis[N-1][j] && grid[N-1][j] == 1)
//             {
//                 dfs(N-1,j,vis,grid,drow,dcol);
//             }
//         }
        
//         //all DFS done
//         int cnt = 0;
//         for(int i=0; i<N; i++)
//         {
//             for(int j=0; j<M; j++)
//             {
//                 if(!vis[i][j] && grid[i][j] == 1)
//                     cnt++;
//             }
//         }
        
//         return cnt;
//     }
// };


// //{ Driver Code Starts.

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n, m;
//         cin >> n >> m;
//         vector<vector<int>> grid(n, vector<int>(m));
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 cin >> grid[i][j];
//             }
//         }
//         Solution obj;
//         cout << obj.numberOfEnclaves(grid) << endl;
//     }
// }
// // } Driver Code Ends