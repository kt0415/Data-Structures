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
    void pre(TreeNode*root, vector<int>&v)
    {
        if(root == NULL)
        {
            v.push_back(0);
            return;
        }
        v.push_back(root->val);
        pre(root->left,v);
        pre(root->right,v);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        vector<int>vp, vq;
        pre(p,vp);
        pre(q,vq);

        int np = vp.size(), nq = vq.size();
        if(np!=nq)
            return false;

        for(int i=0; i<np; i++)
        {
            if(vp[i]!=vq[i])
                return false;
        }

        return true;
    }
};