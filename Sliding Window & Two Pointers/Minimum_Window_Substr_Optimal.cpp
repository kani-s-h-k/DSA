class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m =t.size();
        int l = 0,r=0,minLen=INT_MAX,start=-1,count=0;
        int hash[256]={0};
        for(int i = 0;i<m;i++) hash[t[i]]++;
        while(r<n){
            if(hash[s[r]]>0) count++;
            hash[s[r]]--;
            while(count==m){
                if(r-l+1<minLen){
                    minLen = r-l+1;
                    start = l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0) count--;
                l++;
            }
            r++;
        }
        return start == -1 ? "":s.substr(start,minLen);
    }
};