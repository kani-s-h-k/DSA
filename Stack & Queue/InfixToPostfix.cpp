class Solution {
private:
    int priority(char c){
        if(c=='^') return 3;
        else if(c=='*' || c=='/') return 2;
        else if(c=='+' || c=='-') return 1;
        else return -1;
    }
public:
    string infixToPostfix(string s) {
        stack<char> st;
        string ans = "";
        for(char ch: s){
            if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9')) ans+= ch;
            else if(ch=='(') st.push(ch);
            else if(ch==')'){
                while(!st.empty() && st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() && 
                st.top()!='(' &&  
                (priority(ch)<priority(st.top()) || (priority(ch)==priority(st.top()) && ch !='^'))){
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};