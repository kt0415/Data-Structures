#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // recursive approach
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        return 1 + max(l, r);

    // level order approach
        // int ans = 0;

        // if (root == NULL)
        //     return ans;
        // queue<TreeNode *> q;
        // q.push(root);

        // while (!q.empty())
        // {
        //     int s = q.size();
        //     for (int i = 0; i < s; i++)
        //     {
        //         TreeNode *node = q.front();
        //         q.pop();
        //         if (node->left != NULL)
        //             q.push(node->left);
        //         if (node->right != NULL)
        //             q.push(node->right);
        //     }
        //     ans++;
        // }

        // return ans;
    }
};