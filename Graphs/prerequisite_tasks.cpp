#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) 
	{
	    //create an adjacency list
	    vector<int>adj[N];
	    for(auto it: prerequisites)
	    {
	        adj[it.first].push_back(it.second);
	    }
	    
	    //graph formation complete
	    
	    int cnt = 0;
	    queue<int>q;
	    //indegree array construction..
	    int indegree[N] = {0};
	    for(int i=0; i<N; i++)
	    {
	        for(auto it: adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    
	    //check for nodes with indegree 0
	    for(int i=0; i<N; i++)
	    {
	        if(indegree[i] == 0)
	        {
	            q.push(i);
	        }
	    }
	    
	    //khelo BFS
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        cnt++;
	        
	        //node is into your ans{toposort}.. please remove it from the indegree
	        for(auto it: adj[node])
	        {
	            indegree[it] --;
	            if(indegree[it]==0)
	            {
	                q.push(it);
	            }
	        }
	    }
	   
        if(cnt == N)
            return true;
        return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}