class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int counter=0;
        for(int i= 0;i<s.size();i++){
            if(s[i]=='('){
                if(counter!=0) ans+="(";
                counter++;
            }
            else{
                counter--;
                if(counter!=0) ans+=")";
            }
        }
        return ans;
    }
};