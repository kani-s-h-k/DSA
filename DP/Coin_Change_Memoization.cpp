class Solution {
private:    
    int func(int ind, int target,vector<int> &coins,vector<vector<int>> &dp){
        if(target == 0) return 0;
        if(ind==0){
            if(target%coins[ind]==0) return target/coins[ind];
            return 1e9;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int notTake = func(ind-1,target,coins,dp);
        int take = 1e9;
        if(target>=coins[ind]) take =1 + func(ind,target-coins[ind],coins,dp);
        return dp[ind][target] = min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = func(n-1,amount,coins,dp);
        return (ans>=1e9) ? -1 : ans;
    }
};