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
    bool check(TreeNode* left, TreeNode* right)
    {
        if(left == NULL || right == NULL)
            return left == right;       //if one is NULL, other should also be ... dogh NULL yetil trch he true hoil

        if(left->val!=right->val)
            return false;

        return check(left->left, right->right) && check(left->right, right->left);  //simultaneously checking the right node at right subtree with left node at left subtree and vis a vis
    }

    bool isSymmetric(TreeNode* root)
    {
        if(root == NULL)
            return true;

        if(check(root->left,root->right) == true)
            return true;

        return false;
    }
};