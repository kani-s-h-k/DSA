class Solution {
private:
    int func(int n,vector<int> &nums,vector<int> &dp){
        if(n==0) return nums[n];
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int pick = func(n-2,nums,dp) + nums[n];
        int notPick = func(n-1,nums,dp);
        return dp[n] = max(pick,notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return func(n-1,nums,dp);
    }
};