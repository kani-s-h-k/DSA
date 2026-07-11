class Solution {
private:
    int func(int n, int m, vector<vector<int>>&grid,vector<vector<int>> &dp){
        if(n==0 && m==0)return grid[0][0];
        if(n<0 || m<0) return INT_MAX;
        if(dp[n][m]!=-1) return dp[n][m];
        int up = func(n-1,m,grid,dp);
        int left = func(n,m-1,grid,dp);
        int ans = min(up,left);
        if(ans==INT_MAX) return ans;
        return dp[n][m] = grid[n][m] + ans;
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return func(n-1,m-1,grid,dp);
    }
};