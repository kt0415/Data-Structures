//#Breadth First Search

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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
      vector<vector<int>>ans;   //vector to store all the levels of the binary tree
      if(root == NULL)  return ans;     //base case that if the given tree is empty, we return an empty list
      queue<TreeNode*>q;   //a queue to store the nodes of the tree and whose left and right is going to be checked
      q.push(root);         //firstly, as decided, we insert our root into the queue
      while(!q.empty())     //checking if the queue is empty or not
      {
          int size = q.size();  //getting the size of the queue; at level 1 size will be 1, 2 ke liye 2 , 3 ke liye 4 and so on...
          vector<int>level;     //a vector to store the children values of elements present in the queue
          for(int i=0; i<size; i++) //loop to traverse for the elements of the queue
          {
              TreeNode* node = q.front();   //assigning the frontmost element of queue to a temporary node so that its access can be done using node
              q.pop();                  //popping the frontmost element
              if(node->left!=NULL)      //checking if the node has a node at its left; if it does, insert the left node in queue
                q.push(node->left);
              if(node->right!=NULL)     //checking if the node has a node at its right; if it does, insert the right node in queue
                q.push(node->right);

                level.push_back(node->val); //after getting all the nodes in the queue, use their children and insert their val[values] into level
          }
          ans.push_back(level);     //insert the set of values of each level into the ans data structure
      }

      return ans;   //returning the level-wise values in the tree
    }
};

//TIME COMPLEXITY: O(N); SPACE COMPLEXITY: O(N);