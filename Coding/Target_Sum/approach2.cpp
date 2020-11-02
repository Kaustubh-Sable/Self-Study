class Solution {
    int findTargetSumWays(vector<int>& nums, int S, int i, int currSum, vector<vector<int>> &cache) {
        if(i==nums.size())
            return currSum==S?1:0;
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
       
        if(cache[i][sum+currSum]!=-1)
            return cache[i][sum+currSum];
        
        cache[i][sum+currSum] = findTargetSumWays(nums, S, i+1, currSum+nums[i], cache) + 
                                findTargetSumWays(nums, S, i+1, currSum-nums[i], cache);
                
        return cache[i][sum+currSum];
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size()==0) {
            if(S==0)
                return 1;
            return 0;
        }
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        vector<vector<int>> cache(nums.size(), vector<int>(2*sum+1, -1));
        return findTargetSumWays(nums, S, 0, 0, cache);
    }
};
