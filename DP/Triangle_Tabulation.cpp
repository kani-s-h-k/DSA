class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i = 0;i<triangle[n-1].size();i++) dp[n-1][i] = triangle[n-1][i];
        for(int i = n-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                int down = dp[i+1][j];
                int diag = dp[i+1][j+1];
                dp[i][j] = triangle[i][j] + min(down,diag);
            }
        }
        return dp[0][0];
        
    }
};