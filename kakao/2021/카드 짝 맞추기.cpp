#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {-1, 0, 1, 0}; //위쪽, 오른쪽, 아래쪽, 왼쪽
int dy[4] = {0, 1, 0, -1};

vector<int> findLocation(vector<vector<int>> board, int card) {
    vector<int> result;  //카드1의 x, y, 카드2의 x,y 순
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
               if (board[i][j] == card) {
                   result.push_back(i);
                   result.push_back(j);
               }
               if (result.size() == 4) return result;
        }
    }
}

int calculateDist(int curx, int cury, int destx, int desty) {
    // enter키 포함
    for (int i = 0; i < 4; i++) {
        if (curx == destx && cury == desty) {
            return 1;
        } else if (curx == destx && cury != desty) {
            return 2;
        } else if (curx != destx && cury == desty) {
            return 2;
        } else {
            return 3;
        }
    }
}

int main()
{
    vector<vector<int>> board = {{1, 0, 0, 3}, {2, 0, 0, 0}, {0, 0, 0, 2}, {3, 0, 1, 0}};
    int r = 1, c = 0;
    int answer = 0;
    
    //카드짝 개수 구하기
    int numCard = 0;
    for (auto i : board) {
        for (int j : i) {
            if (numCard < j) numCard = j;
        }
    }
    
    //element 배열 생성
    vector<int> element;
    for (int i = 1; i < numCard+1; i++) {
        element.push_back(i);
    }
    sort(element.begin(), element.end());

    //순열대로 수행
    do {
        int tempRes = 0;
        for (int card : element) {
            auto locations = findLocation(board, card);
            int cardx1 = locations[0];
            int cardy1 = locations[1];
            int cardx2 = locations[2];
            int cardy2 = locations[3];
            int dist1 = calculateDist(r, c, cardx1, cardy1);
            int dist2 = calculateDist(r, c, cardx2, cardy2);
            
            if (dist1 < dist2){
                tempRes += dist1;
                tempRes += calculateDist(cardx1, cardy1, cardx2, cardy2);
                r = cardx2;
                c = cardy2;
            } else {
                tempRes += dist2;
                tempRes += calculateDist(cardx2, cardy2, cardx1, cardy2);
                r = cardx1;
                c = cardy1;
            }
        }
        if (answer == 0 || tempRes < answer) {
            answer = tempRes;
        }
    } while (next_permutation(element.begin(), element.end()));
    
    cout << answer;
    return 0;
}
