class Solution {
    bool solve(int ind, string &s, vector<string> &wordDict){
        if(ind == s.size()) return true;
        for(int i = ind;i<s.size();i++){
            if(inDict(s.substr(ind, i - ind + 1),wordDict)){
                if(solve(i+1, s, wordDict)) return true;
            }
        }
        return false;
    }
    bool inDict(string str, vector<string> &wordDict){
        for(auto &e: wordDict){
            if(e==str) return true;
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return solve(0,s,wordDict);
    }
}; 