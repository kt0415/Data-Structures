#include<bits/stdc++.h>
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

vector<vector<int>> vertical_order_traversal(Node*root)
{
    map<int,map<int,multiset<int>>>m; //map of verticals with multiple levels, each level may/may not have multiple nodes
    queue<pair<Node*,pair<int,int>>>q; //a queue of pair of node - pair of vertical,level
    q.push({root,{0,0}});

    while(!q.empty())       //until our queue becomes empty: sagle nodes complete hoiprent
    {
        //using variables it,x,y,node to get the instanteneous values of the queue's front element, its node, its vertical and its level
        auto it = q.front();    
        q.pop();

        Node* node = it.first;
        int x = it.second.first; 
        int y = it.second.second;

        //inserting into the map 
        m[x][y].insert(node->data);

        //checking for the existence of left and right nodes, if present; being inserted in queue with the corresponding verticals and levels
        if(node->left!=NULL)        
        {
            q.push({node->left,{x-1,y+1}});
        }
        
        if(node->right!=NULL)
        {
            q.push({node->right,{x+1,y+1}});
        }
    }   //vertical order traversal done: map mdhe ahe ata sagl

    vector<vector<int>>ans; //print ithun krnar
    for(auto a: m)  //iterator a will access the map
    {
        vector<int>col; //to store a vector in the vector of vectors
        for(auto b: a.second)   //iterator b to access the map of levels and nodes of each vertical
        {   
            col.insert(col.end(),b.second.begin(), b.second.end());
        }
        ans.push_back(col);
    }

    return ans;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    vector<vector<int>>vertical = vertical_order_traversal(root);

    cout<<"The Vertical Traversal is :- "<<endl;
    for(auto it: vertical)
    {
        cout<<"[ ";
        for(auto pr: it)
        {
            cout<<pr<<" ";
        }
        cout<<"]\n";
    }

    return 0;
}