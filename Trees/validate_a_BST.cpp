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
    bool isValidBST(TreeNode* root) 
    {
        return isValid(root, LONG_MIN, LONG_MAX);   //wrote a function to check if all nodes of BTree are satisfying L<N<R condition so that it can be proved a BST
    }

    bool isValid(TreeNode* root, long minval, long maxval)
    {
        if(root == NULL)    return true;        //base condition
        if(root->val>=maxval || root->val <= minval)        //if our node's value lies outside the prescribed range
            return false;//we can say that L<N<R isnt followed and BTree aint a BST .. so return false
        return isValid(root->left,minval,root->val) && isValid(root->right,root->val,maxval);   //set range for Left Subtree as well as Right Subtree and compare simultaneously...
    }
};