#include <bits/stdc++.h>
using namespace std;


vector<int> ac(vector<int> &nums){
    stack<int> st;
    for(int el : nums){
        if(el>0) st.push(el);
        else{
            while(!st.empty() && st.top()>0 && st.top()<abs(el)) st.pop();
            if(!st.empty() && st.top() == abs(el)) st.pop();
            else if(st.empty() || st.top()<0) st.push(el);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.insert(ans.begin(),st.top());
        st.pop();
    }
    return ans;
}
int main() {
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i =0;i<n;i++){
	    cin>>nums[i];
	}
    vector<int> ans = ac(nums);
    for(auto it: ans){
        cout<<it<<" ";
    }
}
