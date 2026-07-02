class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxCount = 0;
        for(int i  = 0;i<s.size();i++){
            int hash[256] = {0}, len = 0;
            for(int j = i;j<s.size();j++){
                if(hash[s[j]]==1) break;
                len = j -i + 1;
                hash[s[j]]=1;
            }
            maxCount = max(len,maxCount);
        }
        return maxCount;
    }
};