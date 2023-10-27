#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void LHSview(Node *root, vector<int> &ans)
{
    queue<pair<Node *, int>> q; // pair of node-level
    map<int, int> m;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        Node *node = it.first;
        int lvl = it.second;

        m[lvl] = node->data;

        if (node->right != NULL)
        {
            q.push({node->right, lvl + 1});
        }

        if (node->left != NULL)
        {
            q.push({node->left, lvl + 1});
        }
    }

    for (auto pr : m)
    {
        ans.push_back(pr.second);
    }
}

void printvec(vector<int> v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans;

    LHSview(root, ans);

    cout << "The right-side view of the given Binary Tree is:- ";
    printvec(ans);

    return 0;
}