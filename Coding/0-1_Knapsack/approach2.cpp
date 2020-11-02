#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int W, vector<int> wt, vector<int> val, int index, vector<vector<int>> cache) {
    if(index==wt.size())
        return 0;
    
    if(wt[index]>W)
        return knapsack(W, wt, val, index+1, cache);
        
    if(cache[index][W]!=-1)
        return cache[index][W];
        
    cache[index][W] = max( knapsack(W, wt, val, index+1, cache), 
                          val[index] + knapsack(W-wt[index], wt, val, index+1, cache) );
    
    return cache[index][W];
}

int knapsack(int W, vector<int> wt, vector<int> val) {
    vector<vector<int>> cache(wt.size(), vector<int>(W+1, -1));
    return knapsack(W, wt, val, 0, cache);
}

int main()
{
    vector<int> val = { 6, 10, 12 };
    vector<int> wt = { 2, 2, 3 };
    int W = 5;
    cout << knapsack(W, wt, val);
    return 0;
}
