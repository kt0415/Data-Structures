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

class BSTIterator {
private:
    stack<TreeNode*>st;
    bool x = true;  //x true asel tr before(), naitr next() .. karan next() func la ulta way ni bnvl tr before() func ch bnel

    void pushAll(TreeNode* node)
    {
        while(node!=NULL)
        {
            st.push(node);
            if(x == true)
                node = node -> right;
            else
                node = node -> left;
        }
    }

public:
    BSTIterator(TreeNode* root, bool isnext) 
    {
        x = isnext;
        pushAll(root);
    }
    
    int next() 
    {
        TreeNode* top = st.top();
        st.pop();
        if(x == false)
            pushAll(top -> right);
        else
            pushAll(top->left);
        return top -> val;
    }
    
    bool hasNext() 
    {
        return !st.empty(); //if stack is not empty, it returns true, else false   
    }

};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) 
    {
        if(root == NULL)
            return false;
        //for next
        BSTIterator l(root,false);
        //for before
        BSTIterator r(root,true);

        int i = l.next();
        int j = r.next();

        while(i<j)
        {
            if(i+j == k)
                return true;
            else if(i+j > k)
                j = r.next();
            else
                i = l.next();
        }

        return false;
    }
};