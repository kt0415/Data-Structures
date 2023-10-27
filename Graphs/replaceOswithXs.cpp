#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col,  vector<vector<int>>&vis, vector<vector<char>>&mat, int drow[], int dcol[])
{
    vis[row][col] = 1;
    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && vis[nrow][ncol] == 0 && mat[nrow][ncol] == 'O')
        {
            dfs(nrow,ncol,vis,mat,drow,dcol);
        }
    }
    
}
vector<vector<char>>calculate(int n, int m, vector<vector<char>>mat)
{
    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};

    vector<vector<int>>vis(n,vector<int>(m,0));
    //for first and last row
    for (int j = 0; j < m; j++)
    {
        //first row .. 0th row
        if(!vis[0][j] && mat[0][j]=='O')
        {
            dfs(0,j,vis,mat,drow,dcol);
        }   
        //last row .. n-1th row
        if(!vis[n-1][j] && mat[n-1][j]=='O')
        {
            dfs(n-1,j,vis,mat,drow,dcol);
        }
    }
    
    //for first and last column
    for(int i=0; i<n; i++)
    {
        //first column .. 0th column
        if(!vis[i][0] && mat[i][0] == 'O')
        {
            dfs(i,0,vis,mat,drow,dcol);
        }

        //last colummn .. m-1th column
        if(!vis[i][m-1] && mat[i][m-1] == 'O')
        {
            dfs(i,m-1,vis,mat,drow,dcol);
        }
    }

    //all DFS traversals done ... now we have to check the unvisited Os and convert them into Xs

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(!vis[i][j] && mat[i][j] == 'O')
            {
                mat[i][j] = 'X';
            }
        }
    }
    
    return mat;
}
int main()
{
    vector<vector<char>>mat
    {
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'X', 'O', 'O'}
    };

    vector<vector<char>>ans = calculate(5,4,mat);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}