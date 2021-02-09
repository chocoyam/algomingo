/**
*
* https://github.com/ndb796/python-for-coding-test/blob/master/16/1.cpp
*
**/

#include <iostream>

#define MAX 20

using namespace std;

int n = 3;
int m = 4;
    
bool isValid(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    } else {
        return true;
    }
}

int main()
{
    int map[MAX][MAX] = {{1, 3, 1, 5}, {2, 2, 4, 1}, {5, 0, 2, 3}, {0, 6, 1, 2}};
    int res[MAX][MAX] = {{0, },};
    
    //res 첫번째 열 값 채우기
    for (int i = 0; i < n; i++) {
        res[i][0] = map[i][0];
    }
    
    //res[i,j] = map[i,j] + max(res[i-1,j-1], res[i,j-1], res[i+1, j-1])
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            int leftUp = isValid(i-1, j-1) ? res[i-1][j-1] : 0;
            int left = isValid(i, j-1) ? res[i][j-1] : 0;
            int leftDown = isValid(i+1, j-1) ? res[i+1][j-1] : 0;

            res[i][j] = map[i][j] + max(leftUp, max(left, leftDown));
        }
    }
    
    //마지막 열에 있는 데이터 중 가장 큰 값 출력
    int max = 0;
    for (int i = 0; i < n; i++) {
        max = (max < res[i][m-1]) ? res[i][m-1] : max;
    }
    cout << max;
    return 0;
}
