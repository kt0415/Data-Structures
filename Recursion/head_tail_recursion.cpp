#include <iostream>
using namespace std;

// tail recursion
// void fun(int n)
// {
//     if(n>0){
//     cout<<n<<endl;
//     fun(n-1);
//     }
// }

// head recursion
void fun(int n)
{
    if(n>0){
    fun(n-1);
    cout<<n<<endl;
    }
}

int main(){
    int x = 3;
    fun(x);
    return 0;
}