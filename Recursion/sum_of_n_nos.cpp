#include <iostream>
using namespace std;

//recursive sum
int sum(int n)
{
    if(n==0)
        return 0;
    else
    return sum(n-1) + n;
}

//iterative sum
int Isum(int n)
{
    int s=0,i;
    for ( i = 1; i < n; i++)
    {
        s= s+i;
    }
    return s;   
}

int main(){
    int r;
    // r = sum(6);
    r = Isum(7);
    cout<<r<<endl;
    return 0;
}