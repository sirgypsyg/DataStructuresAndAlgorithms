#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

bool fun(std::vector<std::pair<int,int>> room){
    int n = room.size(); 

    bool column[n];
    std::fill(column, column + n, false);

    for (int i = 0; i < n; i++)
    {
        bool change = false;
        for (int j = room[i].first; j <= room[i].second; j++){
            if (column[j] == true)
                continue;
            else{
                column[j] = true;
                change = true;
                break;
            }
        }
        if (change!=true)
            return false;
    }
    return true;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t, n;
    std::cin >> t;
    std::vector<std::pair<int,int>> room

    for (int i = 0; i < t; i++)
    {
        std::cin >> n;
        
        int temp1 , temp2;
        for (int j = 0; j < n; j++){
            std::cin >> temp1 >> temp2;
            room.push_back(std::make_pair(temp1,temp2));
        }
        std::sort(room.begin(), room.end(), [](std::pair<int,int> a, std::pair<int,int> b) {
        return a.second < b.second;});

        std::cout << (fun(room) ? "TAK" : "NIE") << "\n";
        room.clear();
    }
    

    return 0;
}