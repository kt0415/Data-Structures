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

void printvec(vector<int>v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" "; 
    }
    cout<<endl;
}

vector<int> MorrisInorder(Node* root)
{
    vector<int>ans;
    if(root == NULL)
        return ans;
    
    Node* curr = root;
    while(curr != NULL)
    {
        if(curr->left == NULL)
        {
            ans.push_back(curr->data);
            curr = curr -> right;
        }

        else
        {
            Node* temp = curr->left;
            while(temp->right!=NULL && temp->right!=curr)      //temp isnt null and the rightmost guy isnt pointing to curr root till now
            {
                temp = temp -> right;
            }

            if(temp->right == NULL)
            {
                temp->right = curr; //thread attached
                curr = curr->left;
            }

            else
            {
                temp->right = NULL;         //thread removal
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return ans;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);

    vector<int>inorder = MorrisInorder(root);

    cout<<"The Morris Traversal Inorder is:- ";
    printvec(inorder);

    return 0;
}