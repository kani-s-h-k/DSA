class Solution {
private:
    int func(int n, vector<int> &heights,vector<int> &dp){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int left = func(n-1,heights) + abs(heights[n]-heights[n-1]);
        int right = INT_MAX;
        if(n>1) right = func(n-2,heights) + abs(heights[n]-heights[n-2]);
        return dp[n] = min(left,right);
    }
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n+1,-1);
        return func(n-1,heights,dp);
    }
};