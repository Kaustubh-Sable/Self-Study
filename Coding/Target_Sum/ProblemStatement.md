**Question:** 
https://leetcode.com/problems/target-sum/

You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now 
you have 2 symbols + and -. For each integer, you should choose one from + and - as 
its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

**Example**<br>
Input: nums is `[1, 1, 1, 1, 1]`, S is `3`. <br>
Output: `5`<br>
<br>
Explanation: <br>
-1+1+1+1+1 = 3<br>
+1-1+1+1+1 = 3<br>
+1+1-1+1+1 = 3<br>
+1+1+1-1+1 = 3<br>
+1+1+1+1-1 = 3<br>

There are 5 ways to assign symbols to make the sum of nums be target 3.

Constraints:<br>
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.

**Solution approaches:**

I'll be solving it in three ways:
1. Recursive solution (Brute Force)
2. Recursive solution using Memoization (Top-down dynamic programming solution)
3. Iterative solution (Bottom-up dynamic programming solution)
