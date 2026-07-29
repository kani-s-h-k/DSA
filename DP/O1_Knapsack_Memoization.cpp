class Solution {
  private:
    int func(int ind, int W, vector<int> &val, vector<int> &wt,vector<vector<int>> &dp){
        if(ind==0){
            if(wt[ind]<=W) return val[ind];
            return 0;
        }
        if(dp[ind][W]!=-1) return dp[ind][W];
        int notTake = func(ind-1,W,val,wt,dp);
        int take= INT_MIN;
        if(wt[ind]<=W) take = val[ind] + func(ind-1,W-wt[ind],val,wt,dp);
        return dp[ind][W] = max(take,notTake);
    }  
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
        return func(n-1,W,val,wt,dp);
    }
};