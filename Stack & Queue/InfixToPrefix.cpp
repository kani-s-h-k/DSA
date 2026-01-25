#include <bits/stdc++.h>
using namespace std;

int priority(char ch){
    if(ch=='^') return 3;
    else if(ch=='*' || ch=='/') return 2;
    else if(ch=='+' || ch=='-') return 1;
    else return -1;
}
void reverse(string &s,int start, int end){
    while(start<=end){
        swap(s[start],s[end]);
        start++;
        end--;
    }
}
string infixToPrefix(string s){
    int n = s.length();
    int i =0;
    stack<char> st;
    string ans="";
    
    reverse(s,0,n-1);
    
    while(i<n){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) ans+=s[i];
        else if(s[i]==')') st.push(s[i]);
        else if(s[i]=='('){
            while(!st.empty() && st.top()!=')'){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            if(s[i]=='^'){
                while(!st.empty() && priority(s[i])<=priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
            }
            else{
                while(!st.empty() && priority(s[i])<priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    
    reverse(ans,0,ans.length()-1);
    
    return ans;
}


int main() {
	string s;
	cin>>s;
	string res = infixToPrefix(s);
	cout<<res<<" ";
    return 0;
}
