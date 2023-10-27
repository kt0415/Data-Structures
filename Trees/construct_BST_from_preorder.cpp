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
    TreeNode* construct(vector<int>&pre, int&i, int upperbound)
    {
        if(i == pre.size() || pre[i]>upperbound)    //if all elements have been inserted or upper bound requirement cant be satisfied by any node...
            return NULL;

        TreeNode* root = new TreeNode(pre[i++]);    //constructing the node and incrementing i to access further elements of preorder   
        root -> left = construct(pre,i,root->val);  //for root's left, updating the upperbound with root's value
        root -> right = construct(pre,i,upperbound);    //for root's right, maintaining the upperbound value as of the prev node

        return root;    //once everything is done, return the root of constructed BST
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        int i = 0;
        return construct(preorder,i,INT_MAX);
    }
};