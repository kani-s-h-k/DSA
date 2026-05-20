class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<string> st;
        string ans = "";
        for(int i= 0;i<s.size();i++){
          if(s[i]=='('){
                if(!st.empty()) ans+=string(1,s[i]);
                st.push(string(1,s[i]));
          }
          else{
                st.pop();
                if(!st.empty()) ans+=")";
          }
        }
        return ans;
    }
};