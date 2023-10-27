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

class NodeVal
{
public:
    int maxnode, minnode, size;

    NodeVal(int minnode, int maxnode, int size)
    {
        this->maxnode = maxnode;
        this->minnode = minnode;
        this->size = size;
    }
};

class Solution
{
private:
    NodeVal largest(TreeNode* root)
    {
        if(root == NULL)    //empty tree has BST of size 0
            return NodeVal(INT_MAX,INT_MIN,0);

        //post-order, get values from right and left subtree
        auto left = largest(root->left);
        auto right = largest(root->right);

        //current node is greater than max in left and min in right, then it is indeed a BST
        if(left.maxnode <root->val && root->val<right.minnode)
        {
            return NodeVal(min(root->val,left.minnode),max(root->val,right.maxnode), left.size+right.size+1);   //updated the minimal and maximal values
        }

        //otherwise return [-INT,INT] so that parent cannot be a valid BST
        return NodeVal(INT_MIN,INT_MAX,max(left.size,right.size));
    }

public:
    int largestBST(TreeNode* root)
    {
        return largest(root).size;
    }
};