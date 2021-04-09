/******************

 소수 판별
 
******************/

#include <iostream>
#include <math.h>

using namespace std;

bool isPrimeNumber(int n)
{
    for (int i = 2; i <= int(sqrt(n)); i++) {
        if (n % i == 0) return false;
    }
    return true;
}


int main()
{
    cout << isPrimeNumber(2);

    return 0;
}
