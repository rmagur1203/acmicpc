# 최소 신장 트리(Minimum Spanning Tree)
각 간선의 가중치의 합이 최소가 되는 신장 트리

## 프림 알고리즘(Prim's Algorithm)
그리디 알고리즘을 이용합니다.
1. 그래프와 비어 있는 최소 신장 트리를 만듦
2. 임의의 정점을 시작 정점으로 선택하고 최소 신장 트리의 루트 노드로 삽입
3. 최소 신장 트리에 속한 정점과 인접한 정점의 가중치중 가장 작은 가중치를 가진 정점을 최소 신장 트리에 삽입.
    * (사이클을 막기 위해 연결된 정점이 이미 트리가 속한다면 무시)
4. 모든 정점이 최소 신장 트리에 연결될 때 까지 반복
    * (간선의 가중치를 더해서 최소 신장 트리 비용 산출)

### 시간복잡도
<img style="background: white;" src="./images/O(VlogV+ElogV).svg">

일반적으로 E가 V보다 크기 때문에

<img style="background: white;" src="./images/O(ElogV).svg">

## 크루스칼 알고리즘(Kruskal's Algorithm)
유니온-파인드 알고리즘을 이용합니다.
1. 그래프 내의 모든 간선의 가중치를 오름차순으로 정렬
2. 오름차순으로 정렬된 가중치를 순회하면서 최소 신장 트리에 삽입

### 시간복잡도
<img style="background: white;" src="./images/O(ElogE).svg">

## 비교
* Sparse Graph는 크루스칼 알고리즘이 유리
* Dense Graph는 프림 알고리즘이 유리