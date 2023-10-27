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
    TreeNode* attach(TreeNode* root)
    {
        if(root -> left == NULL)
            return root -> right;

        else if(root -> right == NULL)
            return root -> left;

        TreeNode* leftchild = root -> left;
        TreeNode* lastleft = findlastleft(root -> right);
        lastleft -> left = leftchild;
        return root -> right;
    }

    TreeNode* findlastleft(TreeNode* root)
    {
        if(root -> left == NULL)
            return root;

        return findlastleft(root -> left);
    }

    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root == NULL)
            return NULL;

        if(root -> val == key)
            return attach(root);

        TreeNode* curr = root;
        while(curr != NULL)
        {
            if(curr -> val > key)
            {
                if(curr -> left != NULL && curr -> left -> val == key)
                {
                    curr -> left = attach(curr -> left);
                    break;
                }

                else
                    curr = curr -> left;
            }

            else
            {
                if(curr -> right != NULL && curr -> right -> val == key)
                {
                    curr -> right = attach(curr -> right);
                    break;
                }

                else
                    curr = curr -> right;
            }
        } 
        return root;
    }
};