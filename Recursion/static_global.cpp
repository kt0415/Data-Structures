#include <iostream>
using namespace std;

int x = 0;  //x is declared globally here

int fun(int n)
{
    // static int x = 0; //x is a static variable declared within the function fun
    if (n>0)
    {
        x++;
        return fun(n-1) + x;
    }
    return 0;
}

int main(){
    int a = 5;
    cout<<fun(a)<<endl;
    return 0;
}

//both cases{static as well as global declaration}gives same output