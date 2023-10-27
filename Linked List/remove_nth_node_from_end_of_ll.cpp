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
    int getlength(ListNode* head)
    {
        int l = 0;
        ListNode*curr = head;
        
        while(curr!=nullptr)
        {
            l++;
            curr = curr -> next;
        }
        
        return l;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        int l = getlength(head);
        int x = l - n + 1;
        
        if(x==1)
        {
            ListNode* temp = head;
            head = head -> next;
            temp -> next = nullptr;
            delete temp;
        }
        
        else
        {
            ListNode*curr = head;
            ListNode*prev = nullptr;
            
            int cnt = 1;
            while(cnt<x)
            {
                prev = curr;
                curr = curr -> next;
                cnt++;
            }
            
            prev -> next = curr -> next;
            curr -> next = nullptr;
            delete curr;
        }
        
        return head;
    }
};