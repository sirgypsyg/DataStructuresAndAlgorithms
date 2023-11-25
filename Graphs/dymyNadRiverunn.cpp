#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

void BFS(std::vector<std::vector<int> > graph, int n, int s, int d){
  bool visited[n];
  std::fill(visited, visited + n, false);

  std::queue<int> que;

  que.push(s);
  visited[s] = true;

  int maxDist = 0;
  int dist = 0;
  while (!que.empty()){
    bool change = false;
    int head = que.front();
    int edges = graph[head].size();
    que.pop();

    for (int i = 0; i < edges; i++){
      int value = graph[head][i];

      if (!visited[value]){
        visited[value] = true;
        que.push(value);
        change = true;
        if (maxDist < d/2) ++dist;
      }
    }
    if (change) ++maxDist;
  }
  std::cout << maxDist << " " <<  dist;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, m, s, d;
    std::cin >> n >> m >> s >> d; std::cin.ignore();

    std::vector<std::vector<int> > graph(n);

    for(int i = 0; i < m; i++){ 
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    } 

    BFS(graph, n, s, d);
 


    return 0;
}