#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void makeparents(Node *root, unordered_map<Node *, Node *> &track_parent)
{
    queue<Node *> queue;
    queue.push(root);

    while (!queue.empty())
    {
        Node *node = queue.front();
        queue.pop();

        if (node->left != NULL)
        {
            queue.push(node->left);
            track_parent[node->left] = node;
        }

        if (node->right != NULL)
        {
            queue.push(node->right);
            track_parent[node->right] = node;
        }
    }
}

int mintime(Node *root, Node *start)
{
    int time = 0;
    if (root == NULL)
        return time;

    queue<Node *> q;
    unordered_map<Node *, Node *> track_parent;
    makeparents(root, track_parent);
    unordered_map<Node *, bool> visited;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int size = q.size();
        bool f = false;

        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (curr->left != NULL && !visited[curr->left])
            {
                f = true;
                q.push(curr->left);
                visited[curr->left] = true;
            }

            if (curr->right != NULL && !visited[curr->right])
            {
                f = true;
                q.push(curr->right);
                visited[curr->right] = true;
            }

            if (track_parent[curr] != NULL && !visited[track_parent[curr]])
            {
                f = true;
                q.push(track_parent[curr]);
                visited[track_parent[curr]] = true;
            }
        }

        if(f == true)
            time++;
    }

    return time;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->right = new Node(7);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    Node *start = root->left;
    int ans = mintime(root, start);
    cout << "The minimum time to burn the tree from the given start node " << start->data << " is " << ans << " units" << endl;

    return 0;
}