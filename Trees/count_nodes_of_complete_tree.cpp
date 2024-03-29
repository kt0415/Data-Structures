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
    int leftheight(TreeNode* node)
    {
        int lh = 0;
        while(node!=NULL)
        {
            lh++;
            node = node -> left;
        }

        return lh;
    }

    int rightheight(TreeNode* node)
    {
         int rh = 0;
        while(node!=NULL)
        {
            rh++;
            node = node->right;
        }

        return rh;
    }
    int countNodes(TreeNode* root) 
    {
       if(leftheight(root)==rightheight(root))
       {
           int x = leftheight(root);
           x = pow(2,x) - 1;
           return x;
       }

       return 1 + countNodes(root->left) + countNodes(root->right);
    }
};