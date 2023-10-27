#include<bits/stdc++.h>
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

class Solution {
public:
    int maxPathDown(TreeNode* node, int &mx)
    {
        if(node == NULL)
            return 0;

        int ls = max(0,maxPathDown(node->left,mx));
        int rs = max(0,maxPathDown(node->right,mx));

        mx = max(mx, ls+rs+node->val);

        return node->val + max(ls,rs);
    }

    int maxPathSum(TreeNode* root) 
    {
        int mx = INT_MIN;
        maxPathDown(root,mx);
        return mx;    
    }
};