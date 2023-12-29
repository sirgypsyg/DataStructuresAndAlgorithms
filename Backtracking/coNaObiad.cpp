#include <iostream>
#include <algorithm>

void countKcal(int *arr, int index, int &n, int &kcalNeeded, int curKcal, int &counter){
    if (curKcal == kcalNeeded)
        ++counter;
    else if(curKcal < kcalNeeded){
        for (int i = index; i < n; i++)
            countKcal(arr, i+1, n, kcalNeeded, curKcal + arr[i], counter);
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t, n, kcalNeeded;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        std::cin >> n;
        int *arr = new int[n];

        for (int j = 0; j < n; j++)
            std::cin >> arr[j];
        std::sort(arr, arr + n, std::greater<int>());
        std::cin >> kcalNeeded;
        
        int counter = 0;
    
        for (int j = 0; j < n; j++)
        {
            int curKcal = arr[j];
            countKcal(arr, j + 1, n, kcalNeeded, curKcal, counter);
        }
        std::cout << counter << "\n";
        delete []arr;
    }
    return 0;
}