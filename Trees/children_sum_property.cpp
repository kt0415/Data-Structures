#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void childrensum(Node* root)
{
    if(root == NULL)        //base case
        return;

    //moving down the tree
    int child = 0;

    if(root->left!=NULL)
    {
        child += root->left->data;
    }

    if(root->right!=NULL)
    {
        child += root->right->data;
    }

    if(child >= root->data)
        root->data = child;

    else
    {
        if(root->left!=NULL)
            root->left->data = child;

        if(root->right!=NULL)
            root->right->data = child;
    }

    //recursive calls
    childrensum(root->left);
    childrensum(root->right);

    //coming back towards the root: BackTracking
    int total = 0;

    if(root->left!=NULL)
        total += root->left->data;

    if(root->right!=NULL)
        total += root->right->data;

    if(root->left or root->right)
        root->data = total;
}
void inorder(vector<int>&in, Node* root)
{
    if(root == NULL)
    {
        return;
    }

    inorder(in,root->left);
    in.push_back(root->data);
    inorder(in,root->right);
}

void printvec(vector<int>v)
{
    int n = v.size();
    for(int i=0; i<n; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    Node* root = new Node(40);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(12);
    root->left->right = new Node(5);
    root->right->left = new Node(30);
    root->right->right = new Node(41);

    vector<int>btree, updated_btree;
    cout<<"The initial Binary Tree was:- ";
    inorder(btree,root);
    printvec(btree);

    childrensum(root);

    cout<<"The updated Binary Tree is:- ";
    inorder(updated_btree,root);
    printvec(updated_btree);

    return 0;
}