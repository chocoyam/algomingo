## 서로소 집합 (Disjoint Sets)
- 공통 원소가 없는 두 집합
- 두 원소가 부모 노드가 다른지 판별할 때 사용
- 사용하는 연산      
**1. 찾기 (find -> findParent())** - 특정 원소가 속한 집합이 어떤 집합인지 알려줌   
**2. 합집합 (union -> unionParent())**   

### Data Structure
**1. Array**
```
int parent[MAX_NODE];
```
- 각 노드의 부모 정보를 나타내는 배열로, 노드 개수 만큼의 크기를 가짐

### Implementation
```
int v, e;  //v개의 노드와 e개의 간선
int parent[MAX_NODE];

int findParent(int x) {
  if (x == parent[x]) {
    returen x;
  } else {
    return parent[x] = findParent(parent[x]);
  }
}

void unionParent(int a, int b) {
  int a = findParent(a);
  int b = findParent(bP;
  
  if (a < b) {
    parent[b] = a;
  } else {
    parent[a] = b;
  }
}
```
