#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key, value, cnt;
    Node* prev;
    Node* next;
        
    Node(int k, int v)
    {
        key = k;
        value = v;
        cnt = 1;
    }
};
    
struct List
{
    int size;
    Node* head;
    Node* tail;
        
    List() 
    {
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
            
        head -> next = tail;
        tail -> prev = head;
        size = 0;
    }
    
    void addfront(Node* node)
    {
        Node*temp = head -> next;
        node -> next = temp;
        node -> prev = head;
        head -> next = node;
        temp -> prev = node;
        size++;
    }
    
    void removenode(Node* delnode)
    {
        Node* delprev = delnode -> prev;
        Node* delnext = delnode -> next;
        
        delprev -> next = delnext;
        delnext -> prev = delprev;
        
        size--;
    }
};
    

class LFUCache {
public:
    map<int,Node*>keynode;
    map<int,List*>freqlist;
    int maxsize;
    int minfreq = 0;
    int curr = 0;
    
    LFUCache(int capacity) 
    {
        maxsize = capacity;
        minfreq = 0;
        curr = 0;
    }
    
    void updatefreq(Node* node) //function to update freq of our node
    {
        keynode.erase(node->key);   //remove the entry corresponding to the key of the node from the keynode hashmap
        freqlist[node->cnt]->removenode(node);  //we get the list corresponding to node -> cnt from where we remove the node using removenode function
        if(node->cnt==minfreq && freqlist[node->cnt]->size==0)  //if our node was removed from LL of minfreq and if it was the only node in the LL, its removal will make the LL empty, so minfreq has to be incremented
        {
            minfreq++;
        }
        
        List* nexthighfreq = new List();
        if(freqlist.find(node->cnt + 1)!=freqlist.end())    //if there exists a list in the freqlist hashmap with frequency 1 more than our node's frequency
        {
            nexthighfreq = freqlist[node->cnt+1];   //assign that list to our next high freq list   
        }
        node -> cnt += 1;   //increment the freq of our node
        nexthighfreq -> addfront(node); //insert the node into the nexthighfreq list just after head
        freqlist[node->cnt] = nexthighfreq; //updating the freqlist DLL corresponding to the frequency node -> cnt
        keynode[node -> key] = node; 
    }
    
    int get(int k)              //get function 
    {
        if(keynode.find(k)!=keynode.end())   //if key is present in keynode hashmap
        {
            Node* node = keynode[k];        //get the node from the hashmap, call it node
            int val = node -> value;        //use a variable val to store the value corresponding to the key k
            updatefreq(node);               //as we access the node, we update its freq in the freq hashmap
            return val;                     //return the value of key k on the output screen
        }
        
        return -1;              //if key isnt present in keynode hashmap, simply return -1
            
    }
    
    void put(int k, int v)        //put function
    {
        if(maxsize == 0)        //if cache size is 0, nothing can be performed, so return directly
        {
            return;
        }
        
        if(keynode.find(k)!=keynode.end())  //if key k is present in keynode hashmap
        {
            Node* node = keynode[k];    //get the corresponding node from keynode hashmap, store it in node
            node -> value = v;          //updating the value of that node to new value v
            updatefreq(node);           //as the node was accessed, its freq was changed, so update its frequency
        }
        
        else        //key was not initially present in the keynode hashmap
        {
            if(curr==maxsize)   //check if the cache is full/not
            {
                List* list = freqlist[minfreq];     //we access the doubly linked list corresponding to the minimum freq from the freqlist hashmap and assign it to a temporary list
                keynode.erase(list->tail->prev->key);   //we are removing the key corresponding to the LRU of the list we have from the keynode hashmap
                freqlist[minfreq] -> removenode(list->tail->prev); //we remove the LRU node from the list in the freqlist hashmap
                curr--; //we decrease the size of the cache as one node has been removed successfully  
            }
            
            curr++;     //new node being added that wasnt there before and cache isnt full yet
            minfreq = 1;    //the new node is occuring for the first time so its freq would be 1
            List* listfreq = new List();
            
            if(freqlist.find(minfreq)!=freqlist.end())  //if minfreq is present in the freqlist hashmap
            {
                listfreq = freqlist[minfreq];           //the doubly LL corresponding to minfreq is assigned to a newlist called listfreq
            }
            
            Node* node = new Node(k,v); //the new node to be added to our listfreq list is given its key and values here
            listfreq -> addfront(node); //appending the new node in the listfreq list
            keynode[k] = node;          //updating the keynode hashmap with the node address corresponding to key k
            freqlist[minfreq] = listfreq;   //updating the freqlist hashmap with the updated dll listfreq
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */