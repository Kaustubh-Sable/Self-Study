class Solution {
  public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size()==0) {
            if(S==0)
                return 1;
            return 0;
        }
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(abs(S)>abs(sum))
            return 0;
        
        vector<vector<int>> cache(nums.size()+1, vector<int>(2*sum+1, 0));
        cache[0][sum] = 1;
        
        for(int i=1;i<=nums.size();i++)
            for(int j=0;j<2*sum+1;j++)
                if(cache[i-1][j]!=0) {
                    cache[i][j-nums[i-1]] += cache[i-1][j];
                    cache[i][j+nums[i-1]] += cache[i-1][j];
                }

        return cache[nums.size()][sum+S];
    }
};
