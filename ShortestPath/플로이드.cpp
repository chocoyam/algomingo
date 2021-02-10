/**
*
* https://github.com/ndb796/python-for-coding-test/blob/master/17/1.cpp
*
**/

#include <iostream>

#define INF 1e9

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    int map[n+1][n+1];
    fill(map[0], map[0]+(n+1)*(n+1), INF);
    for (int k = 0; k < m; k++) {
        int i, j, value;
        cin >> i >> j >> value;
        map[i][j] = min(map[i][j], value);
    }
    
    //map[i,j] = min(map[i,j], map[i,k] + map[k,j])
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                    map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (map[i][j] == INF || (i == j)) {
                cout << 0 << " ";
            } else {
                cout << map[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
