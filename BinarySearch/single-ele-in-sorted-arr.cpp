//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        int low = 0, high = n-2;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
            if(arr[mid] == arr[mid^1])  //if mid is even idx, mid^1 will return its next odd , if mid is odd idx, mid^1 will return its prev even idx
                low = mid + 1;  
                
            else
                high = mid - 1;
        }
        
        return arr[low];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends