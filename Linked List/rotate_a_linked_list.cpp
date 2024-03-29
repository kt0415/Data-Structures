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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL || head -> next == NULL || k == 0)
            return head;
        
        ListNode *curr = head;
        int len = 1;
        
        while(curr-> next!=NULL)
        {
            len++;
            curr = curr -> next;
        }
        
        k = k%len;
        k = len - k;
        
        curr -> next = head;
        while(k--)
        {
            curr = curr -> next;
        }
        
        head = curr -> next;
        curr -> next = NULL;
        
        return head;
    }
};