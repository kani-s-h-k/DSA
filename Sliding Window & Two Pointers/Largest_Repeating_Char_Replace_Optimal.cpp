class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLen = 0,l=0,r=0,maxFreq=0;
        int hash[26]={0};
        while(r<n){
            hash[s[r]-'A']++;
            maxFreq = max(maxFreq,hash[s[r]-'A']);
            if(((r-l+1)-maxFreq) > k){
                hash[s[l]-'A']--;
                maxFreq = 0;
                for(int i = 0;i<26;i++) maxFreq = max(maxFreq,hash[i]);
                l++;
            }
            if((r-l+1)-maxFreq<=k){
                int len = r-l+1;
                maxLen = max(maxLen,len);
            }
            r++;
        }
        return maxLen;
    }
};