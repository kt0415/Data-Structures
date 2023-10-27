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

Node* kth_smallest(Node* root, int&k)
{
    if(root == NULL)
        return NULL;

    Node* left = kth_smallest(root->left,k);
    if(left!=NULL)
        return left;
    k--;

    if(k==0)
        return root;

    return kth_smallest(root->right,k);
}

Node* kth_largest(Node*root,int&k)
{
    if(root == NULL) 
        return NULL;

    Node* right = kth_largest(root->right,k);
    if(right!=NULL)
        return right;
    k--;

    if(k==0)
        return root;

    return kth_largest(root->left,k);
}

int main()
{
    //constructing binary search tree
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->left->left->right = new Node(2);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    cout<<"Enter the value of k: ";
    int k; cin>>k;
    cout<<"\nEnter the value of l: ";
    int l; cin>>l;
    Node* ans1 = kth_smallest(root,k);
    Node* ans2 = kth_largest(root,l);
    cout<<"The kth smallest element of given BST is :-"<<ans1->data<<endl;  
    cout<<"The lth largest element of given BST is:-"<<ans2->data<<endl;  

    return 0;
}