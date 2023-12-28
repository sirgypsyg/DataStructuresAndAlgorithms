#include <iostream>
#include <vector>
#include <algorithm>


void minCost(std::vector<int> &start, std::vector<int> &end, int n, int c, int d){

    int totalTime = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int found = std::upper_bound(start.begin(), start.end(), end[i]) - start.begin();
        if (start.size() != found)
        {
            if (c > d*(start[found] - end[i]))
            {
                end[i] = end[found];

                start.erase(start.begin() + found);
                end.erase(end.begin() + found);
            }
        }
    }
    for (int i = 0; i < start.size(); i++)
    {
        totalTime += c + d*(end[i] - start[i]);
    }
    std::cout << totalTime << "\n";
    
}


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t, n, c, d;
    std::cin >> t;
    std::vector<int> start;
    std::vector<int> end;

    for (int i = 0; i < t; i++)
    {
        std::cin >> n >> c >> d;
        
        int temp1 , temp2;
        for (int j = 0; j < n; j++){
            std::cin >> temp1 >> temp2;
            start.push_back(temp1);
            end.push_back(temp2);
        }
        std::sort(start.begin(), start.end());
        std::sort(end.begin(), end.end());

        minCost(start, end , n, c, d);
        start.clear();
        end.clear();
    }
    

    return 0;
}