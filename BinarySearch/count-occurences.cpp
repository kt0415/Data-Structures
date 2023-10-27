//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int first(int arr[], int n, int x)
    {
        int i = 0;
        int j = n - 1;
        int res = -1;
        while(i<=j)
        {
            int mid = i + (j-i)/2;
            
            if(arr[mid] == x)
            {
                res = mid;
                j = mid - 1;
            }
            
            else if(arr[mid]>x)
                j = mid - 1;
                
            else
                i = mid + 1;
        }
        
        return res;
    }
    
    int last(int arr[], int n, int x)
    {   
        int i = 0;
        int j = n - 1;
        int res = -1;
        while(i<=j)
        {
            int mid = i + (j-i)/2;
            
            if(arr[mid] == x)
            {
                res = mid;
                i = mid + 1;
            }
            
            else if(arr[mid]>x)
                j = mid - 1;
            
            else
                i = mid + 1;
        }
        
        return res;
    }
    
	int count(int arr[], int n, int x) 
	{
	    int f = first(arr,n,x);
	    int l = last(arr,n,x);
	    
	    if(f == -1 && l == -1)
	        return 0;
	        
	    else
	        return l-f+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends