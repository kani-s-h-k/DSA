#include <bits/stdc++.h>
using namespace std;

string postfixToInfix(string s){
    int i =0;
    int n = s.length();
    stack<string> st;
    
    while(i<n){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || s[i]>='0' && s[i]<='9') st.push(string(1,s[i]));
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string con = "("+t2+s[i]+t1+")";
            st.push(con);
        }
        i++;
    }
    return st.top();
}

int main() {
	string s;
	cin>>s;
	string res = postfixToInfix(s);
	cout<<res<<" ";
    return 0;
}
