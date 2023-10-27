#include <bits/stdc++.h>
using namespace std;

void printqueue(queue<int>q)    //wrote a function to print all elements of queue
{
    while(!q.empty())       //unless our queue is empty
    {
        int x = q.front();  //assign the element at front to variable x
        cout<<x<<" ";       //print that x on output screen
        q.pop();            //pop the element at the front {FIFO}
    }
    cout<<endl;
}

int main()
{
    queue<int>q;        //initialisation of a queue
    q.push(17);         //pushing an element into the queue

    q.push(33);
    q.push(4);

    printqueue(q);

    q.pop();        //pops the element at the front of the queue... 17 in this case

    printqueue(q);

    cout<<q.front()<<endl;    //prints the element at the front of the queue  

    cout<<q.back()<<endl;       //prints the last element of the queue

    int s = q.size();       //returns the size of the queue

    return 0;
}