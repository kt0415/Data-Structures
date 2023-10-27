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
    
    ListNode* reverse(ListNode* &head)
    {   
        ListNode*prev = NULL;
        ListNode*fwd = NULL;
        ListNode*curr = head;
        
        while(curr!=NULL)
        {
            fwd = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = fwd;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head)
    {
        if(head == NULL || head -> next == NULL)
            return true;
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        slow -> next = reverse(slow->next);
        slow = slow -> next;

        
        ListNode* dummy = head;
        
        while(slow!=NULL)
        {
            if(dummy -> val != slow -> val)
                return false;
            
            dummy = dummy -> next;
            slow = slow -> next;
        }
        
        return true;
    }
};