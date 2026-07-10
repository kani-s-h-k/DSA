class Solution {
    int func(int n, int last,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(dp[n][last]!=-1) return dp[n][last];
        if(n==0){
            int maxi = INT_MIN;
            for(int i= 0;i<=2;i++){
                if(i!=last) maxi = max(maxi,matrix[0][i]);
            }
            return dp[n][last]=maxi;
        }
        int maxi = INT_MIN;
        for(int i= 0;i<=2;i++){
            if(i!=last){
                int points = matrix[n][i] + func(n-1,i,matrix,dp);
                maxi = max(maxi,points);
            } 
        }
        return dp[n][last]= maxi;
    }
public:
    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return func(n-1, 3, matrix,dp);
    }
};