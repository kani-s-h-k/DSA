class Solution {
    void generateAll(string curr, int close, int open, vector<string> &res, int n){
        if(curr.length()==2*n){
            res.emplace_back(curr);
            return;
        }
        if(open<n) generateAll(curr+'(',close,open+1, res,n);
        if(close<open) generateAll(curr+')',close+1,open,res,n);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateAll("",0,0,res,n);
        return res;
    }
};