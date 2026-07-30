class Solution
{
private:
    int func(int ind, int W, vector<int> &wt, vector<int> &val,vector<vector<int>> &dp){
        if(ind==0){
            if(W>=wt[ind]) return (W/wt[ind]) * val[ind];
            return 0;
        }
        if(dp[ind][W]!=-1) return dp[ind][W];
        int notTake = func(ind-1,W,wt,val,dp);
        int take = INT_MIN;
        if(W>=wt[ind]) take = val[ind] + func(ind,W-wt[ind],wt,val,dp);
        return dp[ind][W] = max(take,notTake);
    }

public:
   int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
        return func(n-1,W,wt,val,dp);
    }
};
