class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = accumulate(nums.begin(),nums.end(),0);
        if(target%2==1) return false;
        target /=2;
        vector<vector<bool>> dp(n,vector<bool> (target+1,false));
        for(int i= 0;i<n;i++) dp[i][0] = true;
        if(target>=nums[0])dp[0][nums[0]] = true;
        for(int i = 1;i<n;i++){
            for(int j =1;j<=target;j++){
                bool notTake = dp[i-1][j];
                bool take = false;
                if(j>=nums[i]) take = dp[i-1][j-nums[i]];
                dp[i][j] = notTake || take;
            }
        }
        return dp[n-1][target];
    }
};