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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        map<int,int>inMap;

        for(int i=0; i<inorder.size(); i++)
        {
            inMap[inorder[i]] = i;
        }    

        TreeNode* root = build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1, inMap);
        return root;
    }

    TreeNode* build(vector<int>&preorder, int preStart, int preEnd, vector<int>&inorder, int inStart, int inEnd, map<int,int>&inMap)
    {
        if(preStart>preEnd || inStart>inEnd)
            return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]); //first value la binary tree ch root bnvl

        int inRoot = inMap[root->val]; //index of our root {node that is inserted in the Btree}
        int numsLeft = inRoot - inStart;    //how many elements are on the left of the node inserted

        root->left = build(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,inMap);
        root->right = build(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,inMap);

        return root;
    }
};