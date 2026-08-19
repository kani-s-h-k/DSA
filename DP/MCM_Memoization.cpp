class Solution{
    private:
        int mcm(int i, int j,vector<int> &nums,vector<vector<int>> &dp){
            if(i==j) return 0;
            if(dp[i][j]!=-1) return dp[i][j];
            int mini = 1e9;
            for(int k= i;k<=j-1;k++){
                int operations = (nums[i-1] * nums[k] * nums[j]) + mcm(i,k,nums, dp) + mcm(k+1,j,nums, dp);
                mini = min(mini,operations);
            }
            return dp[i][j] = mini;
        }
	public:
		int matrixMultiplication(vector<int>& nums){
            int n = nums.size();
            if(n==1) return 0;
            vector<vector<int>> dp(n,vector<int>(n,-1));
            return mcm(1,n-1,nums,dp);
    	}
};