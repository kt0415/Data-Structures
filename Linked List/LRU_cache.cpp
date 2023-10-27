#include <bits/stdc++.h>
using namespace std;

class LRUCache 
{
public:
    class Node      //structure of a doubly linked list
    {
      public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int k, int v)
        {
            key = k;
            val = v;
        }
        
    };
    
    Node* head = new Node(-1,-1);   //dummy head
    Node* tail = new Node(-1,-1);   //dummy tail
        
    int cap;                        //to denote the size of LRU Cache
    unordered_map<int,Node*> m;     //specifying the hashmap
    
    LRUCache(int capacity)          //to ensure our initial configuration's is ready 
    {       
        cap = capacity;             //assigning the user defined size of LRU Cache to cap
        head -> next = tail;
        tail -> prev = head;
    }
    
    void addnode(Node* newnode)     //adding a new node just after the head of the doubly linked list
    {
        Node* temp = head -> next;  //the node that was initially present just after the head is assigned as temp
        newnode -> next = temp;     //our newnode's next is made to point to this temp
        newnode-> prev = head;      //our newnode's prev is made to point to head
        head -> next = newnode;    //the head's next is made to point to our newnode
        temp -> prev = newnode;     //temp's prev is made to point to our newnode
        
    }
    
    void deletenode(Node* delnode)  // to delete node whose address is given
    {
        Node* delprev = delnode -> prev;    //assigning delprev as the node prev to the node to be deleted
        Node* delnext = delnode -> next;    //assigning delnext as the node next to the node to be deleted
        delprev -> next = delnext;
        delnext -> prev = delprev;
        //adjusting the pointers of the delprev and delnext so that our deleted node isnt attached to anything
    }
    
    int get(int k) 
    {
        if(m.find(k)!=m.end())  //if key does exists in the hashmap
        {
            Node* resnode = m[k];   //assign node's address using m[k] to resnode
            int res = resnode -> val;   //setting the value corresponding to key to res
            m.erase(k);             //removing the entry from the hashmap
            deletenode(resnode);    //deleting the node from the doubly linked list
            addnode(resnode);       //inserting the same node just after head
            m[k] = head -> next;    //setting the address of the key as shown in the hashmap
            return res;             //returning the value to output screen
        }
        return -1;          //if key doesn't exist, we return -1
    }
    
    void put(int k, int v) //inserting a key,value pair in cache
    {
        if(m.find(k)!=m.end())  //if the key was already present in the hashmap
        {
            Node* existing = m[k];  //assign our current node to existing node
            m.erase(k);             //delete the current entry of key from the hashmap
            deletenode(existing);   //delete the node from the doubly linked list
        }
        
        if(m.size()==cap)       //if the key wasnt already present in hashmap and size of map is equal to cache size...
        {
            m.erase(tail->prev->key);    //we erase the key corresponding to the LRU node
            deletenode(tail->prev);      //we remove the LRU node from the doubly linked list
        }
        
        //once the deletion is done, we add the new node {key:value} in the cache as shown below
        addnode(new Node(k,v));     //inserting the new node in the doubly LL
        m[k] = head -> next;        //setting the address of the new node in the hashmap
    }   
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */