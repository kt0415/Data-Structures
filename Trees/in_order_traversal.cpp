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

void inorder(Node* node, vector<int>&in) //left-root-right
{
    if(node == NULL)
        return;

    inorder(node->left,in);
    in.push_back(node->data);
    inorder(node->right,in);
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
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(9);
    root->right->left->right = new Node(10);

    vector<int>in;

    inorder(root,in);

    cout<<"THE IN-ORDER TRAVERSAL OF THE GIVEN BINARY TREE IS:- ";
    print(in);

    return 0;
}