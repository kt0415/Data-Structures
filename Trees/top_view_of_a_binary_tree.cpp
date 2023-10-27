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

void TopView(Node*root, vector<int>&ans)
{
    queue<pair<Node*,int>>q;    //queue of pair of Node and line
    map<int,int>m;                //map of line and Node's data
    q.push({root,0});

    while(!q.empty())
    {
        //using variables  it,node,l to get the instanteneous value of front element of queue, its node and its line
        auto it = q.front();
        q.pop();

        Node* node = it.first;  
        int l = it.second;

        //inserting in the map
        if(m.find(l)==m.end())      //if given line isnt already there in the map, then insert it in map
        {
            m[l] = node->data;
        }

        //doing level order traversal, checking for the existence of left and right nodes
        if(node->left!=NULL)
        {
            q.push({node->left, l - 1});
        }

        if(node->right!=NULL)
        {
            q.push({node->right,l + 1});
        }
    }//when queue becomes empty, the level order traversal is completed and we have our top view elements in map

    for(auto it: m)
    {
        ans.push_back(it.second);
    }
}

void printvec(vector<int>v)
{
    int n = v.size();
    for (int  i = 0; i < n; i++)
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
    root->left->right->left =  new Node(6);
    root->right->right = new Node(7);

    vector<int>ans;

    TopView(root,ans);

    cout<<"The top view of the given Binary Tree is:- ";
    printvec(ans);

    return 0;
}