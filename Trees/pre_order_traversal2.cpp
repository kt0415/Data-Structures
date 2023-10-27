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

vector<int> iterative_preorder(Node* node)
{
    vector<int>pre;
    if(node == NULL)
        return pre;

    stack<Node*>st;

    st.push(node);
    while(!st.empty())
    {
        node = st.top();
        st.pop();
        pre.push_back(node->data);

        if(node->right!=NULL)
            st.push(node->right);

        if(node->left!=NULL)
            st.push(node->left);
    }

    return pre;
}

int main()
{
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(7);

    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);

    vector<int>ans;
    ans = iterative_preorder(root);

    cout<<"The Iterative solution to the Pre-Order traversal of our given Binary Tree is:- ";
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}