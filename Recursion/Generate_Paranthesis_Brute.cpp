class Solution {
    bool isValid(string curr){
        int balance = 0;
        for(char c: curr){
            if(c=='(') balance++;
            else balance--;
            if(balance<0) return false;
        }
        return balance==0;
    }
    void generateAll(string curr, int n, vector<string> &res){
        if(curr.length()==2*n){
            if(isValid(curr)) res.emplace_back(curr);
            return;
        }
        generateAll(curr+'(',n,res);
        generateAll(curr+')',n,res);
    }

    vector<string> generate(int n){
        vector<string> res;
        generateAll("",n,res);
        return res;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res = generate(n);
        return res;
    }
};