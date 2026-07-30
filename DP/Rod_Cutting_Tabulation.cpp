class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        for(int i= 0;i<=n;i++) dp[0][i] = i*price[0];
        for(int i= 1;i<n;i++){
            for(int j = 0;j<=n;j++){
                int notTake = dp[i-1][j];
                int take = INT_MIN;
                int rodLength = i+1;
                if(j>=rodLength) take = price[i] + dp[i][j-rodLength];
                dp[i][j] = max(take,notTake);
            }
        }
        return dp[n-1][n];
    }
};