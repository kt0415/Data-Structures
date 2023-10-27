#include <iostream>
using namespace std;

// recursive factorial
int factorial(int n)
{
    if(n==0)
        return 1;
    else
        return factorial(n-1)*n;
}

// iterative factorial
int Ifactorial(int n)
{
    int f=1,i;
    for ( i = 1; i < n; i++)
    {
        f = f*i;
    }
    return f;
}

int main()
{
    int a;
    // a = factorial(7);
    a = Ifactorial(7);
    cout<<a<<endl;
    return 0;
}