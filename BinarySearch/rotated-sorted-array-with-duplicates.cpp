//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    bool Search(int n, vector<int>&arr, int k) {
        int low = 0;
        int high = n - 1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            if(arr[mid] == k)
                return true;
                
            if(arr[mid] == arr[low] && arr[mid] == arr[high])
            {
                low++;
                high--;
            }
                
            if(arr[low]<=arr[mid])
            {
                if(arr[low]<=k && arr[mid]>=k)
                    high = mid - 1;
                    
                else
                    low = mid + 1;
            }
            
            else
            {
                if(arr[mid]<=k && arr[high]>=k)
                    low = mid + 1;
                    
                else
                    high = mid - 1;
            }
        }
        
        return false;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends