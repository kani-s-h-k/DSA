class Solution {
  private:
    int func(int ind1, int ind2,string &str1, string &str2,vector<vector<int>> &dp){
        if(ind1 == 0 || ind2 == 0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(str1[ind1-1]==str2[ind2-1]) return dp[ind1][ind2] =  1 + func(ind1-1,ind2-1,str1,str2,dp);
        return dp[ind1][ind2] =  max(func(ind1-1,ind2,str1,str2,dp) , func(ind1,ind2-1,str1,str2,dp));
    }
  public:
    int lcs(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return func(n,m,str1,str2,dp);
    }
};
