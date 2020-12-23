#include <iostream>
#include <string>
using namespace std;

int n, m;
int curX, curY, curDir;
int directionX[4] = {0, -1, 0, 1};
int directionY[4] = {-1, 0, 1, 0};
int backX[4] = {1, 0, -1, 0};
int backY[4] = {0, -1, 0, 1}; 

int nextDirection(int curDir)
{
    return (--curDir < 0) ? 3 : curDir;  
}

bool checkBoundary(int x, int y)
{
    if ((0 <= x < n) && (0 <= y < m)) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    cin >> n >> m >> curX >> curY >> curDir;
    
    int map[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    map[curX][curY] = 1;
    int count = 1;
    int tryCount = 0;
    while (1) {
        curDir = nextDirection(curDir);
        int tempX = curX + directionX[curDir];
        int tempY = curY + directionY[curDir];
        
        if (checkBoundary(tempX, tempY) && (map[tempX][tempY] == 0)) {
            curX = tempX;
            curY = tempY;
            map[tempX][tempY] = 1;
            count++;
            tryCount = 0;
        } else {
            tryCount++;
            
            if (tryCount == 4) {
                tempX = curX + backX[curDir];
                tempY = curY + backY[curDir];
                if (checkBoundary(tempX, tempY) && (map[tempX][tempY] == 0)) {
                    curX = tempX;
                    curY = tempY;
                    map[tempX][tempY] = 1;
                    count++;
                    tryCount = 0;
                } else {
                    break;
                }
            }
        }
    }
    cout << count;
    return 0;
}
