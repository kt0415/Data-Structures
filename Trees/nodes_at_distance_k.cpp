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

void assignparents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &track_parent)
{
    queue<TreeNode *> queue;
    queue.push(root);

    while (!queue.empty())
    {
        TreeNode *Treenode = queue.front();
        queue.pop();

        if (Treenode->left != NULL)
        {
            track_parent[Treenode->left] = Treenode;
            queue.push(Treenode->left);
        }

        if (Treenode->right != NULL)
        {
            track_parent[Treenode->right] = Treenode;
            queue.push(Treenode->right);
        }
    }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    unordered_map<TreeNode *, TreeNode *> track_parent;
    assignparents(root, track_parent);

    unordered_map<TreeNode *, bool> visited;
    queue<TreeNode *> q;
    q.push(target);
    visited[target] = true;

    int dis = 0;

    while (!q.empty())
    {
        int size = q.size();

        if (dis++ == k)
            break;

        for (int i = 0; i < size; i++)
        {
            TreeNode *Treenode = q.front();
            q.pop();

            if (Treenode->left != NULL && !visited[Treenode->left])
            {
                q.push(Treenode->left);
                visited[Treenode->left] = true;
            }

            if (Treenode->right != NULL && !visited[Treenode->right])
            {
                q.push(Treenode->right);
                visited[Treenode->right] = true;
            }

            if (track_parent[Treenode] != NULL && !visited[track_parent[Treenode]])
            {
                q.push(track_parent[Treenode]);
                visited[track_parent[Treenode]] = true;
            }
        }
    }

    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        ans.push_back(curr->val);
    }

    return ans;
}

void printvec(vector<int>v)
{
    for(auto it: v)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}

int main()
{
    TreeNode* root = new TreeNode(3);
    root->right = new TreeNode(1);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    vector<int>k_dist_Treenodes;
    TreeNode* target = root->right->right;
    k_dist_Treenodes = distanceK(root,target,2);

    cout<<"The Treenodes that are at a distance k from the target Treenode are:- ";
    printvec(k_dist_Treenodes);

    return 0;
}