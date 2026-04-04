#include <bits/stdc++.h>
using namespace std;

vector<int> func(vector<int> &nums, int k){
	vector<int> res;
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i = 0;i<=k && i<nums.size();i++){
		pq.push(nums[i]);
	}
	for(int i = k+1;i<nums.size();i++){
		res.emplace_back(pq.top());
		pq.pop();
		pq.push(nums[i]);
	}
	while(!pq.empty()){
		res.emplace_back(pq.top());
		pq.pop();
	}
	return res;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("E:/sublime/input.txt","r",stdin);
	freopen("E:/sublime/output.txt","w",stdout);
#endif
						//Code Starts Here

	int n,k;
	cin>>n;
	vector<int> nums(n);
	for(int i = 0;i<n;i++){
		cin>>nums[i];
	}
	cin>>k;
	vector<int> ans = func(nums,k);
	for(auto it:ans){
		cout<<it<<" ";
	}
	
	return 0;

}