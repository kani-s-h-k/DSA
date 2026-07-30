class Solution
{
public:
   int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<vector<int>> dp(n,vector<int>(W+1,0));
        for(int i = 0;i<=W;i++) if(i>=wt[0]) dp[0][i] = (i/wt[0]) * val[0];
        for(int i= 1;i<n;i++){
            for(int j = 0;j<=W;j++){
                int notTake = dp[i-1][j];
                int take = INT_MIN;
                if(j>=wt[i]) take = val[i] + dp[i][j-wt[i]];
                dp[i][j] = max(take,notTake);
            }
        }
        return dp[n-1][W];
    }
};
