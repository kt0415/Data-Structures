//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head)
    {
        if(head -> next == NULL)    return head;
        
        Node* evenhead = NULL;
        Node* eventail = evenhead;
        Node* oddhead = NULL;
        Node* oddtail = oddhead;
        
        Node* curr = head;
        while(curr!=NULL)
        {
            int x = curr -> data;
            Node* temp = new Node(x);
            if(x%2==0)
            {
                if(evenhead == NULL)
                {
                    evenhead = temp;
                    eventail = temp;
                }
                
                else
                {
                    eventail -> next = temp;
                    eventail = eventail -> next;
                }
            }
            
            else
            {
                if(oddhead == NULL)
                {
                    oddhead = temp;
                    oddtail = temp;
                }
                
                else
                {
                    oddtail -> next = temp;
                    oddtail = oddtail -> next;
                }
            }    
            
            curr = curr -> next;
        }
        
        if(evenhead == NULL)    return oddhead;

        if(oddhead!=NULL)
            eventail -> next = oddhead;
            
        return evenhead;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends