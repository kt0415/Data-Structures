//the iterative approach

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

void iterative_inorder(Node*root,vector<int>&in)
{
    stack<Node*>st;
    Node* node = root;

    while(1)
    {
        if(node!=NULL)
        {
            st.push(node);
            node = node -> left;
        }

        else
        {
            if(st.empty() == true)  break;
            
            node = st.top();
            st.pop();
            in.push_back(node->data);
            node = node->right;
        }
    }
}

void printvec(vector<int>v)
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
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    vector<int>ans;
    iterative_inorder(root,ans);

    cout<<"The Iterative solution to the In-Order traversal of our given Binary Tree is:- ";
    printvec(ans);

    return 0;
}