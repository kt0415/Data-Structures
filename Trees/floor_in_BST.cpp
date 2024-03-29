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

int floorInBST(TreeNode  * root, int X)
{
    // Write your code here.
    int floor = -1;
    
    while(root != NULL)
    {
        if(root -> val  == X)
        {
            floor = root -> val;
            break;
        }
        
        if(root -> val < X)
        {
            floor = root -> val;
            root = root -> right;
        }
        
        else
        {
            root = root -> left;
        }
    }
    
    return floor;
}