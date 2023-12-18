#include <iostream>
#include <cmath>

double maxLoc(int nStart, int nEnd, int m){
    //max for column
    double max = -1;
    int curM = 0;
    int curN = (nStart + nEnd)/2;
    for (int i = 0; i < m; i++)
        if (P(curN,i) > max){
            max = P(curN,i);
            curM = i;
        }
            
    //check L & R
    if (nStart == nEnd)
        return max;
    else{ 
        double R = P(curN + 1, curM);
        if (curN == nStart){
            if (R > max)
                return maxLoc(curN + 1, nEnd, m);
            else return max;
        }
            
        double L = P(curN - 1, curM); 
        
        if (L>R)
        {
            if (L > max)
            return maxLoc(nStart, curN - 1, m);
        }
        if (R > max)
            return maxLoc(curN + 1, nEnd, m);
    }
    return max;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    long int n, m;
    std::cin >> n >> m;

    std::cout << int(std::floor(maxLoc(1, n, m)));

    
    return 0;
}