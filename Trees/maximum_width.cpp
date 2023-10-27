#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

int widthOfBinary(Node *root)
{
    if (root == NULL) // if root is null, kya max width... direct 0 print krdo
        return 0;

    int width = 0;
    queue<pair<Node *, int>> q; // queue of pair of node - index
    q.push({root, 0});          // initially inserting root in the queue

    while (!q.empty())
    {
        int s = q.size();
        int mn = q.front().second; // for making starting index 0

        int first, last;
        for (int i = 0; i < s; i++) // updating the indexes of subsequent levels
        {
            int idx = q.front().second - mn;
            Node *node = q.front().first;
            q.pop();

            if (i == 0)
                first = idx;

            if (i == s - 1)
                last = idx;

            // level order
            if (node->left)
                q.push({node->left, idx * 2 + 1});

            if (node->right)
                q.push({node->right, idx * 2 + 2});
        }
        width = max(width, last - first + 1);
    }
    return width;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(5);
    root->left->left->left = new Node(7);
    root->right = new Node(2);
    root->right->right = new Node(4);
    root->right->right->right  = new Node(6);

    int width = widthOfBinary(root);

    cout<<"The maximum width of given binary tree is:- "<<width<<endl;

    return 0;
}