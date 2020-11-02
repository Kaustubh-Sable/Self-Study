#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int W, vector<int> wt, vector<int> val) {
    vector<vector<int>> cache(wt.size()+1, vector<int>(W+1, 0));
    
    for(int i=1;i<=val.size();i++)
        for(int j=1;j<=W;j++) {
            if(wt[i-1]>j)
                cache[i][j] = cache[i-1][j];
            else {
                cache[i][j] = max( cache[i-1][j], 
                                    val[i-1] + cache[i-1][j-wt[i-1]] );
            }
        }
    
    return cache[val.size()][W];
}

int main()
{
    vector<int> val = { 6, 10, 12 };
    vector<int> wt = { 2, 2, 3 };
    int W = 5;
    cout << knapsack(W, wt, val);
    return 0;
}
