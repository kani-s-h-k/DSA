class Solution {
private:
    int func(int n, vector<int> &heights, int k,vector<int> &dp){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int minSteps = INT_MAX;
        for(int i = 1;i<=k;i++){
            if(n-i>=0){
                int jump = func(n-i,heights,k,dp) + abs(heights[n] - heights[n-i]);
                minSteps = min(minSteps, jump);
            }
        }
        return dp[n]=minSteps;
    }
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n+1,-1);
        return func(n-1,heights,k,dp);
    }
};
