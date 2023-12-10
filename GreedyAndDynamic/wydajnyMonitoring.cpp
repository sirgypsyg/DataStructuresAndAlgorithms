#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>



bool fun(int a[], int b[], int n){
    bool column[n];
    for (int i = 0; i < n; i++)
        column[i] = false;
    

    for (int i = 0; i < n; i++)
    {
        bool change = false;
        for (int j = a[i]; j <= b[i]; j++)
        {
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

    for (int i = 0; i < t; i++)
    {
        std::cin >> n;
        int a[n];
        int b[n];
        int temp1 , temp2;
        for (int i = 0; i < n; i++){
            std::cin >> temp1 >> temp2;
            a[i] = temp1;
            b[i] = temp2;
        }
        std::sort(a, a + n);
        std::sort(b, b + n);
        std::cout << (fun(a, b, n) == true ? "TAK" : "NIE");
    }
    

    return 0;
}