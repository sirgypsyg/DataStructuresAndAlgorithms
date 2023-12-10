#include <iostream>
#include <vector>
#include <queue>
#include <climits>

    struct Vert {
        int x, y;
        int mPoints;
        int dist;

        Vert() : x(0), y(0), mPoints(0), dist(INT_MAX) {}

        Vert(int xVal, int yVal, int mPointsVal, int distVal)
        : x(xVal), y(yVal), mPoints(mPointsVal), dist(distVal) {}
    };

    struct VertComparator {
        bool operator()(const Vert& v1, const Vert& v2) const {
            if (v1.dist > v2.dist || (v1.dist == v2.dist && v1.mPoints > v2.mPoints))
                return true;
            return false;
        }
    };

    bool isValid(int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    int whatField(char cell) {
        switch (cell)
        {
        case 'M':
            return 0;
        case 'X':
            return 1;
        case '.':
            return 2;
        }
        return 0;
    }

    void bfs(std::vector<std::vector<char> > &map, int startX, int startY) {
        int n = map.size();
        int m = map[0].size();

        std::priority_queue<Vert, std::vector<Vert>, VertComparator> q;
        std::vector<std::vector<Vert> > v(n, std::vector<Vert>(m));
        v[startX][startY] = Vert(startX, startY, 0, 0);

        q.push(v[startX][startY]);

        while (!q.empty()) {
            Vert current = q.top();
            q.pop();

            int x = current.x;
            int y = current.y;

            // adj edges
            int dx[] = {-1, 0, 1, 0}; // move vertically
            int dy[] = {0, 1, 0, -1}; // move horizontally

            for (int i = 0; i < 4; ++i) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                //SM    que:  . , M, 
                //.X
                if (isValid(newX, newY, n, m) && v[newX][newY].dist == INT_MAX && map[newX][newY] != '#') {
                    switch (whatField(map[newX][newY]))
                    {
                    case 0: // monitored 
                        v[newX][newY] = Vert(newX,newY, current.mPoints + 1, current.dist + 1); 
                        q.push(v[newX][newY]);
                        break;
                    case 1: // X = END
                        std::cout << current.dist + 1 << " " << current.mPoints;
                        return;
                    case 2: // .
                        v[newX][newY] = Vert(newX,newY, current.mPoints, current.dist + 1);   
                        q.push(v[newX][newY]);
                        break;
                    }
                }
            }
        }
    }

    int main() {
        int n, m;
        std::cin >> n >> m;

        std::vector<std::vector<char> > map(n, std::vector<char>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cin >> map[i][j];
            }
        }

        int startX, startY;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (map[i][j] == 'S') {
                    startX = i;
                    startY = j;
                }
            }
        }

        bfs(map, startX, startY);

        return 0;
    }
