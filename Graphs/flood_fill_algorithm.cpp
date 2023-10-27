#include <bits/stdc++.h>
using namespace std;

#define fastIO \
    ios_base::sync_with_stdio(0); \
    cin.tie(0); \
    cout.tie(0); 

void dfs(int row, int col, vector<vector<int>>&val, vector<vector<int>>&image, int newColor, int initColor, int delRow[], int delCol[])
{
    val[row][col] = newColor;   //assigning the starting piece with the new color
    int n = image.size();
    int m = image[0].size();

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delRow[i];     //neighbouring row...
        int ncol = col + delCol[i];         //neighbouring column...

        if(nrow>=0 && nrow<n && ncol>=0 && ncol <m && image[nrow][ncol] == initColor && val[nrow][ncol] != newColor)
            dfs(nrow,ncol,val,image,newColor,initColor,delRow,delCol);
    }
    
}
vector<vector<int>>floodFill(vector<vector<int>>&image, int sr, int sc, int newColor)
{
    int initColor = image[sr][sc];
    vector<vector<int>>val  = image;

    int delRow[] = {-1,0,+1,0};
    int delCol[] = {0,+1,0,-1};

    dfs(sr,sc,val,image,newColor,initColor,delRow,delCol);
    return val;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        fastIO;
        int n,m;
        cin>>n>>m;

        vector<vector<int>>image(n,vector<int>(m,0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin>>image[i][j];
            }
        }
        
        int sr,sc,newColor;
        cin>>sr>>sc>>newColor;

        vector<vector<int>>ans = floodFill(image,sr,sc,newColor);

        for(auto i: ans)
        {
            for(auto j: i)
                cout<<j<<" ";
            cout<<endl;
        }

    }
    return 0;
}