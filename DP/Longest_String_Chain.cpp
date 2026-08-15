class Solution {
private:
    bool compare(string &word1, string &word2){
        if(word1.size()-word2.size()!=1) return false;
        int i = 0,j = 0;
        while(i<word1.size()){
            if(j<word2.size() && word1[i]==word2[j]){
                i++;
                j++;
            }
            else i++;
        }
        return j==word2.size();
    }
    static bool comp(string &s, string &t){
        return s.size()<t.size();
    }
public:
    int longestStrChain(vector<string>& words) {
       sort(words.begin(),words.end(),comp);
       int n = words.size(),maxi=1;
       vector<int> dp(n,1);
       for(int i = 0;i<n;i++){
        for(int j= 0;j<=i-1;j++){
            if(compare(words[i],words[j]) && dp[i] < 1 + dp[j]){
                dp[i] = 1 + dp[j];
            }
        }
        maxi = max(maxi,dp[i]);
       }
       return maxi;
    }
};