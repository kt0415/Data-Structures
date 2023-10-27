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

public:
    BSTIterator(TreeNode* root) 
    {
       while(root != NULL)
       {
           st.push(root);
           root = root -> left;
       }     
    }
    
    int next() 
    {
        TreeNode* top = st.top();
        st.pop();
        if(top -> right != NULL)
        {
            TreeNode* temp = top -> right;
            while(temp!=NULL)
            {
                st.push(temp);
                temp = temp -> left;
            }
        }
        return top -> val;
    }
    
    bool hasNext() 
    {
        return !st.empty(); //if stack is not empty, it returns true, else false   
    }

};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */