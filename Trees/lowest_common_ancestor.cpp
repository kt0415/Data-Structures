#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (root == NULL || root == p || root == q) // if we reach NULL, we have to return it to the upper node, else if we reach our desired node, we still have to return it... Hence this condition
        return root;

    Node *left = lowestCommonAncestor(root->left, p, q);   // performing DFS left
    Node *right = lowestCommonAncestor(root->right, p, q); // performing DFS right

    if (left == NULL) // null is coming from LHS but RHS != NULL
        return right;

    else if (right == NULL) // null is coming from RHS but LHS != NULL
        return left;

    else // both LHS and RHS are not NULL, so returning their ancestor which might be their LCA
        return root;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(8);
    root->right->right = new Node(9);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    Node* ans = lowestCommonAncestor(root, root->right->left,root->right->right);

    cout<<"The lowest Common Ancestor is:- "<<ans->val<<endl;

    return 0;
}