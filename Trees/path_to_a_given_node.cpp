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

bool getPath(Node* root, vector<int>&path, int x)
{
    if(root == NULL)    //if root is NULL, there is no path... so return false
        return false;

    path.push_back(root->data); //pushing the value in our answer vector

    if(root->data == x)     //if we reach our desired node... return true
        return true;

    //otherwise check if the desired node is there in the left or right subtree
    if(getPath(root->left,path,x) || getPath(root->right,path,x))
        return true;
    //agar us subtree me hai to return kr do true

    //agar nahi hi mila to kya kr skte hai, wo subtree galat thi... last wala element hatana padega aur wapas ake false bolna pdega
    path.pop_back();
    return false;
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

    vector<int>path;
    cout<<"Enter the node, I will tell you the path!!"<<endl;
    int n; cin>>n;

    getPath(root,path,n);

    if(path.size()==0)
        cout<<"This node is not present in the given binary tree!!"<<endl;

    else
    {
        cout<<"Here is your path from root = "<<root->data<<" to the node = "<<n<<endl;
        for (int i = 0; i < path.size(); i++)
        {
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}