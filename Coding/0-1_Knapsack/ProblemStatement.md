**Question:**

Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items 
respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that 
sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or 
don’t pick it (0-1 property).

**Example**

For `val[] = { 6, 10, 12 }`, `wt[] = { 2, 2, 3 }` and `W = 5`,

Answer should be `22`

**Solution approaches:**

I'll be solving it in three ways:
1. Recursive solution (Brute Force)
2. Recursive solution using Memoization (Top-down dynamic programming solution)
3. Iterative solution (Bottom-up dynamic programming solution)
