#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int N, vector<vector<int>> &edges, int src)
{
    vector<int> dist(N, 1e8); // declare the distance array and mark all edges as 1e8
    dist[src] = 0;            // source's distance is marked as zero

    for (int i = 0; i < N - 1; i++) // perform N-1 iterations on the given graph
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) // updating the element of distance array
                dist[v] = dist[u] + wt;
        }
    }

    // checking for negative cycle .. doing one more iteration .. ie:- Nth iteration
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            return {-1};
    }

    return dist;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        vector<int> res = bellman_ford(N, edges, src);

        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;

    return 0;
}