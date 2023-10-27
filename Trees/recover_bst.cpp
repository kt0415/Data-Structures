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
private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* mid;
    TreeNode* second;
public:
    void inorder(TreeNode* root)
    {
        if(root == NULL)
            return;

        inorder(root -> left);

        if(prev != NULL && (root->val<prev->val))   //check for violation
        {
            if(first == NULL)   //it is a first violation
            {
                first = prev;
                mid = root;
            }

            else            //it is a second violation
                second = root;
        }
        prev = root;    //marking this node as previous
        inorder(root -> right);
        
    }

    void recoverTree(TreeNode* root) 
    {
        first = mid = second = NULL;
        prev = new TreeNode(INT_MIN);

        inorder(root);

        if(first!=NULL && second!=NULL) //2 violations, non adjacent
            swap(first->val, second -> val);

        else if(first!=NULL && mid!=NULL)   //1 violation, adjacent
            swap(first->val,mid->val);

    }
};