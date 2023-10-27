#include <bits/stdc++.h>
using namespace std;

#define FastIO          \
    ios_base::sync_with_stdio(0);       \
    cin.tie(0);             \
    cout.tie(0);

vector<int>dijkstra(int V, vector<vector<int>>adj[], int S)
{
    /*
    //1] Priority Queue Method
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq; //declared a min-heap / priority queue that stores pair of distance,node in it and keeps the smaller distance ahead ... check notes for clearer understanding
    vector<int>dist(V); //distance vector to store the shortest distance to each node from the source node
    for(int i=0; i<V; i++)  //initialise all distances to 1e9 ~ INT_MAX
    {
        dist[i] = 1e9;
    }
    
    dist[S] = 0;    //make the source's distance to itself as zero
    pq.push({0,S}); //insert the dist 0 and the source node in the priority queue

    while(!pq.empty())  //unless the priority queue becomes empty..
    {
        auto it = pq.top(); //take an iterator to get the topmost element of priority queue
        pq.pop();           //deleting the topmost element from the priority queue
        int node = it.second;   //node of the topmost element of priority queue
        int d = it.first;       //current distance till the topmost element from the source

        for(auto pr: adj[node]) //going through the adjacency list for the neighbours of the current node
        { //as the list contains pairs in the form of {node,weight}, assign suitable variables as shown below to access them
            int wt = pr[1]; 
            int adjnode = pr[0];   
            //check if the distance to the adjnode can be reduced than its current value
            if(wt + d < dist[adjnode])  //if it can indeed be reduced..
            {
                dist[adjnode] = wt + d;     //reduce it here
                pq.push({dist[adjnode],adjnode});   //push the updated dist, node pair in the priority queue
            }
        }
    }

    return dist;
    */

    /**/
    //2] SET METHOD
    set<pair<int,int>>s;
    vector<int>vec(V);
    for(int i=0; i<V; i++)
    {
        vec[i] = 1e9;
    }

    vec[S] = 0;
    s.insert({0,S});

    while(!s.empty())
    {
        auto it = s.begin();
        s.erase(s.begin());
        int node = it->second;
        int dis = it->first;

        for(auto pr : adj[node])
        {
            int wt = pr[1];
            int adjnode = pr[0];

            if(wt + dis < vec[adjnode])
            {
                vec[adjnode] = wt + dis;
                s.insert({vec[adjnode],adjnode});
            }
        }
    }
    
    return vec;
}

int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
    	vector<int> res = dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;

}