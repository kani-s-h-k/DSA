class Solution {
  private:
  public:
    int knapsack(int weight, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n+1,vector<int>(weight+1,0));
        for(int i = wt[0];i<=weight;i++) dp[0][i] = val[0];
        for(int ind = 1;ind<n;ind++){
            for(int W = 0;W<=weight;W++){
                int notTake = dp[ind-1][W];
                int take= INT_MIN;
                if(wt[ind]<=W) take = val[ind] + dp[ind-1][W-wt[ind]];
                dp[ind][W] = max(take,notTake);
            }
        }
        return dp[n-1][weight];
    }
};