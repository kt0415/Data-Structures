//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int arr[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        while(l<=h)
        {
            int mid = (l+h)/2;
            
            if(arr[mid] == key)
                return mid;
                
            if(arr[l]<=arr[mid])  //checking if left part is sorted
            {
                if(arr[l]<=key && arr[mid]>=key)    //if ele lies in the left sorted half, shift high pointer.. shrink searching area to left of mid
                    h = mid - 1;
                    
                else            //this condition means ele doesnt lie in the range, so shift the other pointer
                    l = mid + 1;
            }
            
            else    //then check in sorted right half
            {
                if(arr[mid]<=key && arr[h]>=key)    //if ele is present in right sorted half, shift low pointer... shrink searching area to right of mid
                    l = mid + 1;
                    
                else            //this condition means that ele doesnt lie in range, so shift the other pointer
                    h = mid - 1;
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends