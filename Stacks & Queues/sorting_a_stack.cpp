#include <bits/stdc++.h> 
using namespace std;

void sorted_insert(stack<int>&stack, int n)
{
    if(stack.empty()||(!stack.empty() && stack.top()<n))    //here we initially check if our stack has atleast 1 element and its top is less than the element we are trying to insert or else we have a completely vacant stack
    {
        stack.push(n);      //when our condition is met, we insert our element and return
        return;
    }
    
    int a = stack.top();    //unless that, we assign the value of our top element of our stack to a
    stack.pop();            //then we pop that top element
    sorted_insert(stack,n); //we make a recursive call unless the base case isnt satisfied
    stack.push(a);          //once the recursion is complete, we insert the top element back 
}

void sortStack(stack<int> &stack)
{
//brute force algorithm
//in this algo, we used extra space in the form of vector where we stored all elements of our stack , then we sorted our vector and then inserted those sorted elements back in our empty stack... this approach had a time complexity of O(n) and space complexity of O(n)... so this approach isn't that great
//  vector<int>v;
//     while(!stack.empty())
//     {
//         int x = stack.top();
//         v.push_back(x);
//         stack.pop();
//     }
    
//     sort(v.begin(),v.end());
// //     reverse(v.begin(),v.end());
    
//     for(auto &it: v)
//     {
//         stack.push(it);
//     }
    
//optimised recursive approach
    if(stack.empty())   //our base case is that our stack is empty, it is the point where we return 
        return;
    
    int x = stack.top();    //until then, we assign our top to an integer x, then we pop our top element and make a recursive call to the current function
    stack.pop();            //here the element at top was popped mentioned in above comment
    sortStack(stack);       //recursive call made until base condition not met
    sorted_insert(stack, x);// inserted the element x in a sorted fashion as per the function definition of sorted_insert()....
}