#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>


void BFS(std::vector<std::vector<int> > graph, int n,  int s, int days){
    std::queue<int> que;
    bool visited[n];
    std::fill(visited, visited + n, 0);

    int counter = 0;
    int dist = 0;

    if (graph[s].size()!= 0) {                                //if castle has no roads EDGE CASE
        que.push(s);   
        visited[s] = true;
    }   else {                                                    //no crows were send no one will come
        std::cout << 0 << " " << 0; 
        return;
    }                          
    
    while (!que.empty()){
        int head = que.front();
        int size = graph[head].size();
        que.pop();
        
        bool change = false;
        for (int j = 0; j < size; j++)
        {
            int val = graph[head][j];

            if (!visited[val]){
                change = true;
                visited[val] = true;
                que.push(val);
                if (dist<days/2)
                    ++counter;
            }
        }
        if (change)
            ++dist;
    }

    std::cout << dist << " " << counter;
}


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, m, s, d;
    std::cin >> n >> m >> s >> d; std::cin.ignore();

    std::vector<std::vector<int> > graph(n);

    for(int i = 0; i < m; i++){ 
        int cas1, cas2;
        std::cin >> cas1 >> cas2; std::cin.ignore();
        graph[cas1].push_back(cas2);
        graph[cas2].push_back(cas1);
    } 
 
    BFS(graph, n, s, d);


    return 0;
}