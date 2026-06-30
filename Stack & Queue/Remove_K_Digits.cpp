class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(char ch : num){
            while(!st.empty() && k>0 && (st.top() > ch)){
                st.pop();
                k--;
            }
            st.push(ch);
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        while(!res.empty() && res.back()=='0') res.pop_back();
        if(res.empty()) return "0";
        reverse(res.begin(),res.end());
        return res;
    }
};