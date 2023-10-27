//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Brute Force
// User function template for C++
//  class Solution{
//  public:
//      int rowWithMax1s(vector<vector<int> >&arr, int n, int m)
//  	{
//  	    int ans = -1;
//  	    int ones = 0;
//          for(int i=0; i<n; i++)
//          {
//              int cnt = 0;
//              for(int j=0; j<m; j++)
//              {
//                  if(arr[i][j] == 1)
//                      cnt++;
//              }

//             if(ones<cnt)
//             {
//                 ones = cnt;
//                 ans = i;
//             }
//         }
// 	    return ans;
// 	}
// };

// Binary Search Approach
//  } Driver Code Ends
// User function template for C++
//  class Solution{
//  public:
//      int binarysearch(vector<int>&v)
//      {
//          int i = 0;
//          int j = v.size() - 1;

//         while(i<=j)
//         {
//             int mid = i + (j-i)/2;

//             if(v[mid] == 1)
//                 j = mid - 1;

//             else
//                 i = mid + 1;
//         }

//         return i;
//     }

// 	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
// 	    int row = -1;
// 	    int pos = m;
// 	    for(int i=0; i<n; i++)
// 	    {
// 	        int x = binarysearch(arr[i]);
// 	        if(pos>x)
// 	        {
// 	            pos = x;
// 	            row = i;
// 	        }
// 	    }

// 	    return row;
// 	}
// };

// MOST OPTIMISED APPROACH
// User function template for C++
class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        int col = m - 1;
        int row = -1;

        for (int i = 0; i < n; i++)
        {
            for (int j = col; j >= 0; j--)
            {
                if (arr[i][j] == 1)
                {
                    row = i;
                    col--;
                }

                else
                    break;
            }
        }
        return row;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends