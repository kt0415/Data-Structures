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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == NULL)        //base condition
            return NULL;

        int curr = root->val;   //curr variable to store current node's value
        if(p->val>curr && q->val>curr)  //if both nodes p and q lie to the right side of curr wala node
        {
            return lowestCommonAncestor(root->right,p,q);   //move right and return LCA of right subtree
        }
        if(p->val<curr && q->val<curr)  //if both p & q lie to the left side of curr wala node
        {
            return lowestCommonAncestor(root->left,p,q);    //move left and LCA of left subtree
        }
        //both nodes lie on different sides of curr wala node, so return the curr wala node
        return root;    
    }
};