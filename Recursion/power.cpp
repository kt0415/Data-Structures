#include <iostream>
using namespace std;

int power(int m, int n)
{
    if (n == 0)
        return 1;
    else
        return power(m, n - 1) * m;
}

int power1(int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return power1(m * m, n/ 2);
    return power1(m * m, (n - 1) / 2);
}

int main()
{
    int a;
    // a = power(4,6);
    a = power1(2, 9);
    cout << a << endl;
    return 0;
}