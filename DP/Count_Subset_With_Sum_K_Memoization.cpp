class Solution{
    private:
        int func(int ind, int target, vector<int> &arr,vector<vector<int>> &dp){
            if(ind == 0){
                if(target == 0 && arr[0]==0) return 2;
                if(target == 0 || arr[0] == target) return 1;
                return 0;
            }
            if(dp[ind][target]!=-1) return dp[ind][target];
            int notTake = func(ind-1,target,arr,dp);
            int take = 0;
            if(target>=arr[ind]) take = func(ind-1,target-arr[ind],arr,dp);
            return dp[ind][target] = take + notTake;
        }
	public:
	    int perfectSum(vector<int>&arr, int K){
            int n = arr.size();
            vector<vector<int>> dp(n,vector<int>(K+1,-1));
            return func(n-1,K,arr,dp);
	    }
};