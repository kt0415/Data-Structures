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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode*d1 = headA;
        ListNode*d2 = headB;
        
        while(d1!=d2)
        {
            d1 = d1 == NULL ? headB : d1 -> next;
            d2 = d2 == NULL ? headA : d2 -> next;
        }
        
        return d1;
    }
};