/**
*
* https://github.com/ndb796/python-for-coding-test/blob/master/18/1.cpp
*
**/

#include <iostream>
#define MAX_NODE 500

using namespace std;

int parent[MAX_NODE];

int findParent(int x) {
    if (x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

int unionParent(int a, int b) {
    int parentA = findParent(a);
    int parentB = findParent(b);
    if (parentA < parentB) {
        parent[b] = parentA;
    } else {
        parent[a] = parentB;
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int a;
            cin >> a;
            if (a == 1) {
                unionParent(i, j);  //연결된 노드끼리 union 연산
            }
        }
    }
    
    int route[M];
    for (int i = 0; i < M; i++) {
        cin >> route[i];
    }
    
    bool check = true;
    for (int i = 0; i < M-1; i++) {
        if (parent[route[i]] != parent[route[i+1]]) {
            check = false;
        }
    }
    
    if (check) {
        cout << "yes";
    } else {
        cout << "no";
    }
    
    return 0;
}
