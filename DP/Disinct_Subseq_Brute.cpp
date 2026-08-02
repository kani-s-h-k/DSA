class Solution {
private:
    int func(int i, int j, string &s, string &t){
        if(j<0) return 1;
        if(i<0) return 0;
        if(s[i]==t[j]) return func(i-1,j-1,s,t) + func(i-1,j,s,t);
        return func(i-1,j,s,t);
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        return func(n-1,m-1,s,t);
    }
};