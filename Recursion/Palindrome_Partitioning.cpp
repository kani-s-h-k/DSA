class Solution {
    void generatePartitions(int ind, string s, vector<vector<string>> &res, vector<string> &path){
        if(ind == s.size()){
            res.emplace_back(path);
            return;
        }
        for(int i = ind; 9oi<s.size();i++){
            if(isPalindrome(s,ind,i)){
                path.emplace_back(s.substr(ind,i-ind+1));
                generatePartitions(i+1, s, res, path);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        generatePartitions(0,s,res,path);
        return res;
    }
};