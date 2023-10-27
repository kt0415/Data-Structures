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

class Solution
{
public:
    TreeNode* inorder_successor(TreeNode*root,TreeNode* node)
    {
        TreeNode* successor = NULL;

        while(root !=NULL)
        {
            if(node->val >= root->val)
            {
                root = root -> right;
            }

            else
            {
                successor = root;
                root = root -> left;
            }
        }

        return successor;
    }

    TreeNode* inorder_predecessor(TreeNode*root,TreeNode*node)
    {
        TreeNode* predecessor = NULL;

        while(root != NULL)
        {
            if(node->val <= root->val)
            {
                root = root -> left;
            }

            else
            {
                predecessor = root;
                root = root -> right;
            }
        }

        return predecessor;
    }
};