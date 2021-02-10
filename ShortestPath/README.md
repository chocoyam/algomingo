## Dijkstra
\- 한 지점에서 다른 모든 지점까지의 최단 경로 계산   
\- 그리디 알고리즘, 우선순위 큐 사용   
\- O(ElogV)

### Data Structure
**1. graph**
```
vector<pair<int, int>> graph[MAX_NODE];
```
**2. distance**
```
int distance[MAX_NODE];
```
**3. priority queue**
```
priority_queue<pair<int, int>> prior_queue;
```

## Floyd-Warshall
\- 모든 지점에서 다른 모든 지점까지의 최단 경로 계산   
\- 다이나믹 프로그래밍 사용   
\- 점화식 : G[i,j] = min(G[i,j], G[i,k] + G[k,j])   
\- 중간 노드를 기준으로 구현   
\- O(V^3)

### Data Structure
**1. graph = distance**
```
int graph[MAX_NODE][MAX_NODE];
```
- input 데이터로 주어지는 그래프 정보를 이차원 배열로 저장
- 최단 경로 계산 결과 바로 저장

### Implementation
```
for (int k = 1; k <= nodeNum; k++) {
  for (int i = 1; i <= nodeNum; i++) {
    for (int j = 1; j <= nodeNum; j++) {
      g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}}}
```
