#include<bits/stdc++.h>
using namespace std;


struct ListNode
 {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void insertAtTail(ListNode*&head, ListNode*&tail, int d)
    {
        ListNode*temp = new ListNode(d);
        if(head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        
        else
        {
            tail -> next = temp;
            tail = temp;
        }
        
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        vector<int>v;
        ListNode*curr1 = list1;
        ListNode*curr2 = list2;
        
        while(curr1!=nullptr)
        {
            int a = curr1 -> val;
            v.push_back(a);
            curr1 = curr1 -> next;
        }
        
        while(curr2!=nullptr)
        {
            int b = curr2 -> val;
            v.push_back(b);
            curr2 = curr2 -> next;
        }
        
        sort(v.begin(),v.end());
        
        ListNode*head = nullptr;
        ListNode*tail = nullptr;
        
        for(int i=0; i<v.size(); i++)
        {
            insertAtTail(head,tail,v[i]);   
        }
        
        return head;
        
    }
};