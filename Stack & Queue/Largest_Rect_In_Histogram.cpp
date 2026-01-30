#include <bits/stdc++.h>
using namespace std;

vector<int> nse(vector<int> &nums){
    int n = nums.size();
    stack<int> st;
    vector<int> res(n);
    for(int i = n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
        if(st.empty()) res[i]=n;
        else res[i]=st.top();
        st.push(i);
    }
    return res;
}

vector<int> pse(vector<int> &nums){
    int n = nums.size();
    stack<int> st;
    vector<int> res(n);
    for(int i = 0;i<n;i++){
        while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
        if(st.empty()) res[i]=-1;
        else res[i]=st.top();
        st.push(i);
    }
    return res;
}

int largestRect(vector<int> &nums){
    int n = nums.size();
    int maxArea = INT_MIN;
    vector<int> NSE = nse(nums);
    vector<int> PSE = pse(nums);
    for(int i =0;i<n;i++){
        int width = (NSE[i]-PSE[i]-1);
        int area = width*nums[i];
        maxArea=max(area,maxArea);
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
