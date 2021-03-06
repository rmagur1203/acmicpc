# 벨만-포드 알고리즘
그래프에서 시작 정점부터 나머지 정점까지의 최단거리를 구하는 알고리즘.

가중치가 음수인 그래프의 최단거리도 구할 수 있으며,

가중치가 음수이기 때문에 사이클을 이룰 수 있다.

사이클을 이루는 경우에는 최단경로를 구하는 것 자체가 의미가 없어진다.

https://ratsgo.github.io/data%20structure&algorithm/2017/11/27/bellmanford/

## 시간복잡도
정점의 개수가 V,
간선의 개수가 E일때

시작노드를 제외한 전체 노드수 만큼 모든 엣지에 대해 탐색을 수행하고,

마지막으로 사이클이 있는지 확인하기 위해

그래프 모든 엣지에 대해 탐색을 수행해 주므로,

시간복잡도는 <img style="border-color: white; border: solid; border-radius: 5px; background-color: white; height: 20px;" src="images/O(VE).png">이다.

## 코드
```c++
#define INF 1e9

vector<tuple<int, int, int>> edges;
int dist[501];

void Update() {
    for (int i = 0; i < edges.size(); i++){
        int start = get<0>(edges[i]);
        int end = get<1>(edges[i]);
        int weight = get<2>(edges[i]);

        if (dist[start] == INF) continue;
        if (dist[start] + weight < dist[end])
            dist[end] = dist[start] + weight;
    }
}

bool Bellman_Ford(int n)
{
    dist[1] = 0;
    for (int i = 0; i < n - 1; i++){
        Update();
    }
    for (int i = 0; i < edges.size(); i++){
        int start = get<0>(edges[i]);
        int end = get<1>(edges[i]);
        int weight = get<2>(edges[i]);

        if (dist[start] == INF) continue;
        if (dist[start] + weight < dist[end]) return false;
    }
    return true;
}
```