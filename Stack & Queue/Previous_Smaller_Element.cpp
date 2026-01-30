#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &nums2,int el){
    for(int i =0;i<nums2.size();i++){
        if(el==nums2[i]) return i+1;
    }
    return INT_MAX;
}
vector<int> pse(vector<int> &nums){
    stack<int> st;
    int n = nums.size();
    vector<int> ans(n);
    for(int i = 0;i<n;i++){
       while(!st.empty() && st.top()>=nums[i]) st.pop();
       if(st.empty()) ans[i]=-1;
       else ans[i]=st.top();
       st.push(nums[i]);
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
    vector<int> ans = pse(nums);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}
