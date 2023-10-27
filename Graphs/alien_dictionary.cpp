#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
    vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>ans;
	    queue<int>q;
	    //indegree array construction..
	    int indegree[V] = {0};
	    for(int i=0; i<V; i++)
	    {
	        for(auto it: adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    
	    //check for nodes with indegree 0
	    for(int i=0; i<V; i++)
	    {
	        if(indegree[i] == 0)
	        {
	            q.push(i);
	        }
	    }

	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        
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
	   
	   return ans; 
	}
    
    public:
    string findOrder(string dict[], int N, int K) 
    {
        vector<int>adj[K];
        //going till n-1 because we need pair of strings.. everytime we will be comparing the ith and i+1th string so as to get the links of the graph 
        for(int i=0; i<N-1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            int len = min(s1.size(),s2.size()); //now we want to compare the 2 strings to find the point of conflict.. so we go till the length of the smaller string for comparison
            //as shown..
            for(int j=0; j<len; j++)
            {
                if(s1[j]!=s2[j])
                {//subtacting a so that the ASCII characters/alphabets get converted into integer values .. b - a == 1 , c - a ==2 , a - a == 0 and so on.
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');  //here, we are creating an directed edge from [s1[j]] - 'a' to [s2[j]] - 'a'  
                    break;    
                }
            }
        }
            //we have the adjacency list for the directed graph of characters converted to integers
            //get the topological sort on this directed graph
        
        vector<int>v = topoSort(K, adj);    //get the topological sort of those characters
        string val = "";    //while inserting in the answer string val, we add 'a' to the vector elements so that the characters of alphabet get inserted and not integers 
        for(auto it: v)
        {
            val += char(it + 'a');
        }
        
        return val;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}