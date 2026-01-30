#include <bits/stdc++.h>
using namespace std;


int largestRect(vector<int> &nums){
    int nse, pse,element;
    int n = nums.size();
    int maxArea = INT_MIN;
    stack<int> st;
    for(int i = 0;i<n;i++){
        while(!st.empty() && nums[st.top()]>nums[i]){
            element = st.top();
            st.pop();
            nse = i;
            pse = st.empty() ? -1 : st.top();
            maxArea=max(maxArea, (nse-pse-1)*nums[element]);
        }
        st.push(i);
    }
    while(!st.empty()){
        element = st.top();
        st.pop();
        nse = n;
        pse = st.empty()?-1:st.top();
        maxArea=max(maxArea, (nse-pse-1)*nums[element]);
    }
    return maxArea;
}

int main() {
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i =0;i<n;i++){
	    cin>>nums[i];
	}
    cout<<largestRect(nums);
}
