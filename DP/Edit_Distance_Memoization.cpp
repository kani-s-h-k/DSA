class Solution {
private:
    int func(int i, int j, string &word1,string &word2,vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return dp[i][j] = func(i-1,j-1,word1,word2,dp);
        int insertion = 1 + func(i,j-1,word1,word2,dp);
        int deletion = 1 + func(i-1,j,word1,word2,dp);
        int replace = 1 + func(i-1,j-1,word1,word2,dp);
        return dp[i][j] = min({insertion,deletion,replace});
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return func(n-1,m-1,word1,word2,dp);
    }
};