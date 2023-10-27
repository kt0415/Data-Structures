//the iterative approach using 1 stack only

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

void postorder_1stack(Node* root, vector<int>&ans)
{
    stack<Node*>st;
    Node* curr = root;
    Node* temp = NULL;
    while(curr!=NULL || !st.empty())
    {
        if(curr!=NULL)
        {
            st.push(curr);
            curr = curr -> left;
        }

        else
        {
            temp = st.top()->right;
            if(temp == NULL)
            {
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
                while(!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }

            else
                curr = temp;
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
    root->right = new Node(7);
    root->right->left = new Node(8);
    root->left->left = new Node(3);
    root->left->left->right = new Node(4);
    root->left->left->right->right = new Node(5);
    root->left->left->right->right->right = new Node(6);

    vector<int>ans;
    
    postorder_1stack(root,ans);

    cout<<"The iterative post-order traversal of given binary tree is:- ";
    printvec(ans);

    return 0;
}