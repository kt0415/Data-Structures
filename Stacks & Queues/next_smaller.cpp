#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
//Approach 1: Brute Force: TLE yetay  
    
//     for(int i=0; i<n; i++)
//     {
//         int flag = 1;
//         for(int j=i+1; j<n; j++)
//         {
//             if(arr[i]>arr[j])
//             {
//                 arr[i] = arr[j];
//                 flag = 0;
//                 break;
//             }
//         }
        
//         if(flag)
//         {
//             arr[i] = -1;
//         }
//     }
    
//     return arr;
    
//Solving using Stack : O(n)
    stack<int>st;       //creating a stack to store the elements of array 
    st.push(-1);        //pushing -1 at the bottom of the stack as when we find there is no next smaller element for a specific ith element in arr, we assign arr[i] to -1
    vector<int>ans(n);  //creating a vector ans and storing the new values (next smallest values) in it
    
    for(int i=n-1; i>=0; i--)   //reverse iteration ... n-1 to 0
    {
        int current = arr[i];   
        while(st.top() >= current)  //if the top of stack is not less than current value of arr, we pop the top 
        {
            st.pop();
        }
        
        ans[i] = st.top();      //once the while loop terminates, we get an element at top of stack that is smaller than current
        st.push(current);       //after pushing that top element into our ans vector, we push current value in our stack
    }
    return ans;
}