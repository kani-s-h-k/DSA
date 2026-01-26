#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement2(vector<int> &nums){
    int n = nums.size();
    stack<int> st;
    vector<int> res(n);
    
    for(int i = 2*n-1;i>=0;i--){
        while(!st.empty() && st.top()<=nums[i%n]) st.pop();
        if(i<n){
        if(st.empty()) res[i]=-1;
        else res[i]=st.top();
        }
        st.push(nums[i%n]);
    }
    
    return res;
}

int main() {
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i =0;i<n;i++){
	    cin>>nums[i];
	}
    vector<int> res = nextGreaterElement2(nums);
    for(auto it: res){
        cout<<it<<" ";
    }
    return 0;
}
