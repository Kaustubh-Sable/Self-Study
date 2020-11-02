#include <iostream>
#include <algorithm>
using namespace std;

int knapsack(int W, int wt[], int val[], int n, int index) {
    if(index==n)
        return 0;
        
    if(wt[index]>W)
        return knapsack(W, wt, val, n, index+1);
        
    return max( knapsack(W, wt, val, n, index+1), 
                val[index] + knapsack(W-wt[index], wt, val, n, index+1) );
}

int knapsack(int W, int wt[], int val[], int n) {
    return knapsack(W, wt, val, n, 0);
}

int main()
{
    int val[] = { 6, 10, 12 };
    int wt[] = { 2, 2, 3 };
    int W = 5;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapsack(W, wt, val, n);
    return 0;
}
