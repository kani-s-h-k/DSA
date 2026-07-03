class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLen = 0;
        for(int i = 0;i<n;i++){
            int hash[26]={0};
            int len = 0,maxFreq=0;
            for(int j = i;j<n;j++){
                hash[s[j]-'A']++;
                maxFreq = max(maxFreq, hash[s[j]-'A']);
                int changes = (j-i+1) - maxFreq;
                if(changes>k) break;
                len=j-i+1;
            }
            maxLen = max(maxLen,len);
        }
        return maxLen;
    }
};