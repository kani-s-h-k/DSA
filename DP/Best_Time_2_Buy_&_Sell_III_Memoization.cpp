class Solution {
private:
    int func(int i, int buy, vector<int> &prices, int cap, vector<vector<vector<int>>> &dp){
        if(cap==0) return 0;
        if(i==prices.size()) return 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        if(buy){
            return dp[i][buy][cap] = max(func(i+1,0,prices,cap,dp) - prices[i], func(i+1,1,prices,cap,dp));
        }
        return dp[i][buy][cap] = max(func(i+1,1,prices,cap-1,dp) + prices[i], func(i+1,0,prices,cap,dp));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return func(0,1,prices,2,dp);
    }
};