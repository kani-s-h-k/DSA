class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m =t.size();
        int minLen=INT_MAX,start=0;
        for(int i= 0;i<n;i++){
            int count = 0;
            int hash[256]={0};
            for(int j=0;j<m;j++) hash[t[j]]++;
            for(int j = i;j<n;j++){
                if(hash[s[j]]>0) count++;
                hash[s[j]]--;
                if(count==m && j-i+1<minLen){
                    minLen = j-i+1;
                    start = i;
                    break;
                }
            }
        }
        if(minLen == INT_MAX)
            return "";

        return s.substr(start,minLen);
    }
};