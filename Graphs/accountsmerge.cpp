#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    vector<int> parent, size;

public:
    DisjointSet(int n)
    { // resizing our size and parent vectors to n+1 size in case of 1 based indexing and n size in case of 0 based indexing
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int node) // to find the ultimate parent of the given node using path compression and recursion
    {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]); // path compression done here
    }

    void unionBySize(int u, int v)
    {
        int pu = findParent(u); // ultimate parent of u
        int pv = findParent(v); // ultimate parent of v

        if (pu == pv)
            return; // if they have the same ultimate parent, dont do anything, simply return

        if (size[pu] < size[pv]) // if the pu's component is smaller than that of pv
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }

        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
    int n = accounts.size();
    DisjointSet ds(n); // creating an object of disjoint set
    sort(accounts.begin(), accounts.end());
    unordered_map<string, int> mailnode; // a map to link each mail to its owner's index
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < accounts[i].size(); j++)
        {
            string mail = accounts[i][j];
            if (mailnode.find(mail) == mailnode.end()) // if our current mail is not present in the map of mail-index
                mailnode[mail] = i;                    // mark it in the map then alongside its index

            else
                ds.unionBySize(i, mailnode[mail]); // making the existing value of index in the map ie:- mailnode[mail] for the mail as the ultimate parent of the current index i
        }

        // disjoint set created successfully
        // all emails mapped to their respective indexes successfully

        vector<string> merged[n]; // declaring a vector of array of size n which will store the vector of strings for each index basically to store the mails
        for (auto it : mailnode)
        {
            string mail = it.first;
            int node = ds.findParent(it.second); // to get the ultimate parent of it.second in order to insert our mail at that ultimate parent index in the merged vector
            merged[node].push_back(mail);        // mapped the mail successfully here
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (merged[i].size() == 0)
                continue; // if an index has nothing, dont take it
            sort(merged[i].begin(), merged[i].end());
            vector<string> temp; // inserting the name of the person in our temporary vec of strings
            temp.push_back(accounts[i][0]);
            for (auto it : merged[i])
            {
                temp.push_back(it); // inserting all the mails corresponding to that person in his temp vector
            }
            ans.push_back(temp);
        }

        return ans;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<string>> accounts;

        for (int i = 0; i < n; i++)
        {
            vector<string> temp;
            int x;
            cin >> x;

            for (int j = 0; j < x; j++)
            {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

        vector<vector<string>> res = accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i)
        {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++)
            {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else
                cout << "]";
        }
        cout << "]"
             << endl;
    }
}
