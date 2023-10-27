#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextsmaller(vector<int>arr, int n)  //to get the index of next smaller index of current element
    {
        stack<int>st;
        st.push(-1);
        
        vector<int>ans(n);
        for(int i=n-1; i>=0; i--)
        {
            int curr = arr[i];
            while(st.top()!=-1 && arr[st.top()]>= curr)
            {
                st.pop();
            }
            
            ans[i] = st.top();
            st.push(i);
        }
        
        return ans;
    }
    
    vector<int> prevsmaller(vector<int>arr, int n)  //to get the index of previous smaller element of the current element
    {
        stack<int>st;
        st.push(-1);
        
        vector<int>ans(n);
        for(int i=0 ; i<n; i++)
        {
            int curr = arr[i];
            while(st.top()!=-1 && arr[st.top()]>= curr)
            {
                st.pop();
            }
            
            ans[i] = st.top();
            st.push(i);
            
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
        vector<int>next(n);
        next = nextsmaller(heights,n);  //assigning the value corresponding to next smaller element in the stack to next variable
        
        vector<int>prev(n);
        prev = prevsmaller(heights,n);  //assigning the value corresponding to previous smaller element in the stack to next variable
        
        
        int area = INT_MIN; //checking for maximum area 
        for(int i=0; i<n; i++)
        {
            int l = heights[i]; //length of every rectangle would be equal to its heights[i]
            
            if(next[i] == -1)   //if this happens, width == -1 ; Math Error
            {
                 next[i] = n;   //so next[i]'s value is modified to n
            }
            
            int b = next[i] - prev[i] - 1;  //formula to get the breadth of rectangle
            
            int newarea = l*b;
            area = max(area,newarea);
        }
        return area;
    }
};