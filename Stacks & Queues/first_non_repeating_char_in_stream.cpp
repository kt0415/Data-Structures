#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A)
		{
		    int n = A.length();
		    unordered_map<char,int>m;   //to get count of all characters
		    queue<int>q;                //to check which character are we currently processing
		    
		    string ans = "";            //final ans store kryla
		    
		    for(int i=0; i<n; i++)  
		    {
		        char ch = A[i];
		        m[ch]++;
		        q.push(ch);         
		        
		        while(!q.empty())
		        {
		            if(m[q.front()]>1)
		                q.pop();
		                
		            else
		            {
		                ans.push_back(q.front());
		                break;
		            }     
		        }
		        
		        if(q.empty())
		            ans.push_back('#');
		    }
		    
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}