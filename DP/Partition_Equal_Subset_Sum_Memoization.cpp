class Solution {
private:
    bool func(int ind, int target, vector<int> &nums,vector<vector<int>> &dp){
        if(target == 0) return true;
        if(ind == 0) return (nums[ind] == target);
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool notTake = func(ind-1,target,nums,dp);
        bool take = false;
        if(target>=nums[ind]) take = func(ind-1, target-nums[ind],nums,dp);
        return dp[ind][target] = notTake || take;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(n,vector<int> (target+1,-1));
        if(target%2==0) return func(n-1,target/2,nums,dp);
        return false;
    }
};