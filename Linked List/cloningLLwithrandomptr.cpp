#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        Node *iter = head;
        Node *front = head;
        
        //made a deep copy of each node of our original LL and inserted them in the LL just after the original nodes
        while(iter!=NULL)
        {
            front = iter -> next;
            
            Node* dcopy = new Node(iter -> val);
            iter -> next = dcopy;
            dcopy -> next = front;
            
            iter = front;
        }
        
        //assigning the random pointers of the deep copy nodes
        iter = head;
        while(iter!=NULL)
        {
            if(iter->random != NULL)
            {
                iter->next->random = iter->random->next;
            }
            
            iter = iter -> next -> next;
        }
        
        //extracting the 2 LL seperately
        iter = head;
        Node *pseudo = new Node(0);
        Node *ptr = pseudo;
        
        while(iter!=NULL)
        {
            front = iter -> next -> next;
            
            ptr -> next = iter -> next;
            
            iter -> next = front;
            
            ptr = ptr -> next;
            
            iter = front;
            
        }
        
        return pseudo -> next;
        
    }
};