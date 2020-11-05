/******************************************************************************
https://codeup.kr/problem.php?id=3120

- Input : 현재 온도a 와 목표 온도b가 입력된다. ( 0 <= a , b <= 40 )
  ex) 7 34
- Output : 최소한의 버튼 사용으로 목표온도가 되는 버튼의 횟수를 출력한다.
  ex) 5
*******************************************************************************/

#include <stdio.h>

int main()
{
    int cur, target;
    scanf("%d %d", &cur, &target);
    int temperatures[3] = {10, 5, 1};
    
    int diff = (target - cur < 0) ? (cur - target) : (target - cur);
    
    int count = 0;
    
    if ((diff + 1) % 5 == 0) {
        diff += 1;
        for (int temp : temperatures) {
            count += diff / temp;
            diff = diff % temp;
        }
        count += 1;
    } else if ((diff + 2) % 5 == 0) {
        diff += 2;
        for (int temp : temperatures) {
            count += diff / temp;
            diff = diff % temp;
        }
        count += 2;
    } else {
        for (int temp : temperatures) {
            count += diff / temp;
            diff = diff % temp;
        }
    }
    
    printf("%d", count);
    
    return 0;
}
