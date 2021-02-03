## 최단거리 구하기
graph의 특정 node에서 출발하여 다른 모든 node까지의 최단 경로를 구할때 사용.  
이때 간선의 크기는 모두 1이어야 함.

### Data Structure
#### 1. graph
```
std::vector<int> graph[MAX_NODE]
```
- input 데이터로 주어지는 그래프 정보를 리스트 형태로 저장 하기 위해 사용.  
- int형 vector를 elment로 갖는 배열.  
- 배열의 index(i)는 node 번호를 뜻함.  
- graph[i] 값은 i번째 node와 연결된 노드들의 정보를 나타냄(vector 형태). 

#### 2. distance
```
vector<int> distance(MAX_NODE, -1)
```
- vector의 index는 node를 뜻하고, distance[i]는 i번째 노드의 최단 경로를 의미.
- 처음에 -1로 초기화
- 출발 도시의 경우 경로를 0으로 설정

#### 3. queue
- q.push()
- q.front()
- q.pop()
```
queue<int> q;
q.push(startNode);

while (!q.empty()) {
  int now = q.front();
  q.pop();
  
  std::vector<>
  for (int i = 0; i < graph[now].size(); i++) { //O(N+M), N:node 수, M:간선 수
    int nextNode = graph[now][i];
    
    if (d[nextNode] == -1) {  //-1은 아직 방문하지 않은 도시를 의미
      d[nextNode] = d[now] + 1; //모든 간선 크기는 1
      q.push(nextNode);
    } //end if
  } //end for
} //end while
