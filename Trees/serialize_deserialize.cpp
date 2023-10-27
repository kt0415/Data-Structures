#include <bits/stdc++.h>
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

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string ans = "";
        if (root == NULL) // if there is no tree, return an empty string
            return ans;
        // doing level order traversal
        queue<TreeNode *> q;
        q.push(root); // initially inserted root in queue

        while (!q.empty()) // until the queue is empty
        {
            TreeNode *curr = q.front(); // use a variable curr of type TreeNode* to access the front element of queue
            q.pop();                    // popping the same element

            if (curr == NULL) // if the front element was NULL, append #, to end of the string
                ans.append("#,");
            else
                ans.append(to_string(curr->val) + ','); // or else, convert the node's value to a string using to_string and then append that and a comma to end of ans

            if (curr != NULL) // now if our current node was not NULL, then push its left and right node in the queue
            {
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        // repeats until all nodes covered
        return ans; // returns the obtained string
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return NULL; // if string is empty, it means there was no tree... so return NULL

        stringstream ss(data); // using stringstream function to divide our main data string into substrings
        string str;            // using variable str of type string to access each substring of stringstream ss or basically the data string
        // we had used commas to seperate all the nodes' values ... so we would use getline function to access these string-form-nodes now
        getline(ss, str, ',');                    // the first substring uptil comma is stored in str, this one's int value will be our root's value
        TreeNode *root = new TreeNode(stoi(str)); // so converted that string into int value and made a root TreeNode for it
        queue<TreeNode *> q;                      // again using a queue to add elements to the tree
        q.push(root);                             // initially inserting the newly formed root in the queue

        while (!q.empty()) // unless the queue becomes empty
        {
            TreeNode *node = q.front(); // using node variable to get front element of queue
            q.pop();

            // node's left
            getline(ss, str, ','); // we take the next substring from ss
            if (str == "#")        // if that substring is equal to #, it means our node's left should point to NULL
                node->left = NULL;

            else // alternatively, we use leftnode variable and assign the value of string-to-int converted string str
            {
                TreeNode *leftnode = new TreeNode(stoi(str));
                node->left = leftnode;
                q.push(leftnode);
            }

            // node's right
            getline(ss, str, ',');  //we take the next substring from ss
            if (str == "#")         // if that substring is equal to #, it means our node's right should point to NULL
                node->right = NULL; 

            else // alternatively, we use rightnode variable and assign the value of string-to-int converted string str
            {
                TreeNode *rightnode = new TreeNode(stoi(str));
                node->right = rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};

    // Your Codec object will be instantiated and called as such:
    // Codec ser, deser;
    // TreeNode* ans = deser.deserialize(ser.serialize(root));