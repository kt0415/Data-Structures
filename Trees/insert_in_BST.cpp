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
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        TreeNode* temp = new TreeNode(val);
        if(root == NULL)
            return temp;

        TreeNode* curr = root;
        while(1)
        {
            if(curr -> val <= val)
            {
                if(curr -> right == NULL)
                {
                    curr -> right = temp;
                    break;
                }
                else
                {
                    curr = curr -> right;
                }
            }

            else
            {
                if(curr -> left == NULL)
                {
                    curr -> left = temp;
                    break;
                }

                else
                {
                    curr = curr -> left;
                }
            }
        }    

        return root;
    }
};