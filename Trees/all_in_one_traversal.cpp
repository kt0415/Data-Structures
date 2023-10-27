//WOW Question and WOW approach

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

void alltraversal(Node*root, vector<int>&pre, vector<int>&in, vector<int>&post)
{
    stack<pair<Node*, int>> st;
    st.push({root,1});

    if(root == NULL)
        return;

    while(!st.empty())
    {
        auto it = st.top();
        st.pop();
        
        if(it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left!=NULL)
            {
                st.push({it.first->left, 1});
            }
        }

        else if(it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->right!=NULL)
            {
                st.push({it.first->right,1});
            }
        }

        else
        {
            post.push_back(it.first->data);
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
    Node*root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> pre;
    vector<int>in;
    vector<int>post;

    alltraversal(root,pre,in,post);

    cout<<"The pre-order traversal of given Binary Tree is:- ";
    printvec(pre);

    cout<<"The in-order traversal of given Binary Tree is:- ";
    printvec(in);

    cout<<"The post-order traversal of given Binary Tree is:- ";
    printvec(post);

    return 0;
}