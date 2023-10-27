#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)   //constructor
    {
        data = val; 
        left = NULL;
        right = NULL;
    }
};

void postorder(Node* node, vector<int>&post)    //left-right-root
{
    if(node == NULL)
        return;

    postorder(node->left,post);
    postorder(node->right,post);
    post.push_back(node->data);
}

void print(vector<int>v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    Node* root = new Node(4);
    root->left = new Node(5);
    root->left->left = new Node(6);
    root->left->right = new Node(1);
    root->left->right->left = new Node(3);
    root->right = new Node(7);
    root->right->left = new Node(2);
    root->right->right = new Node(9);
    root->right->right->left = new Node(11);
    root->right->right->right = new Node(23);

    vector<int>post;
    postorder(root,post);

    cout<<"THE POST-ORDER TRAVERSAL OF GIVEN BINARY TREE IS:- ";
    print(post);

    return 0;
}