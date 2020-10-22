#include <stdio.h>

int main()
{
    int num = 0;  //동전 개수
    int rest;  //거스름돈
    scanf("%d", &rest);
    int coins[4] = {500, 100, 50, 10};  //동전 종류
    
    for (int coin : coins) {
        num += rest / coin;  //동전 개수는 몫의 합
        rest = rest % coin;  //거스름돈은 나머지
    }
    
    printf("%d", num);
    
    return 0;
}
