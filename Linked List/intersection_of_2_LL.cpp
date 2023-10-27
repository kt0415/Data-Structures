//#common nodes in LL1 and LL2

//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}


// } Driver Code Ends
/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        unordered_map<int,int>ump;
        Node* curr1 = head1;
        Node* curr2 = head2;
        
        while(curr2!=NULL)
        {
            int x = curr2 -> data;
            ump[x]++;
            curr2 = curr2 -> next;
        }
        
        Node* anshead = new Node(-1);
        Node* anstail = anshead;
        
        while(curr1!=NULL)
        {
            int x = curr1 -> data;
            if(ump[x]>0)
            {
                Node* temp = new Node(x);
                anstail -> next = temp;
                anstail = anstail -> next;
            }
            
            curr1 = curr1 -> next;
        }
        anshead = anshead -> next;
        return anshead;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    
	    cin>> n;
	    Node* head1 = inputList(n);
	    
	    cin>>m;
	    Node* head2 = inputList(m);
	    Solution obj;
	    Node* result = obj.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends