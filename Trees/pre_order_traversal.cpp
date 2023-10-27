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

void preorder(Node* node, vector<int>&pre)  //root-left-right
{
    if(node == NULL)
        return;

    pre.push_back(node->data);
    preorder(node->left, pre);
    preorder(node->right,pre);
}

void print(vector<int>v)
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
    vector<int>pre;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->left = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    preorder(root,pre);

    cout<<"THE PRE-ORDER TRAVERSAL FOR THE GIVEN BINARY TREE WILL BE:- ";
    print(pre);

    return 0;
}