class Solution {
    int findTargetSumWays(vector<int>& nums, int S, int i, int currSum) {
        if(i==nums.size())
            return currSum==S?1:0;
        
        return findTargetSumWays(nums, S, i+1, currSum+nums[i]) + 
                findTargetSumWays(nums, S, i+1, currSum-+nums[i]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return findTargetSumWays(nums, S, 0, 0);
    }
};
