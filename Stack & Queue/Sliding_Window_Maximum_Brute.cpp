#include <bits/stdc++.h>
using namespace std;

vector<int> swm(vector<int> &nums,int k){
    vector<int> ans;
    int n = nums.size();
    for(int i=0;i<=(n-k);i++){
        int maxi = nums[i];
        for(int j =1;j<k;j++){
            maxi=max(nums[i+j],maxi);
        }
        ans.emplace_back(maxi);
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
	int k;
	cin>>k;
	vector<int> res = swm(nums,k);
	for(auto it: res){
	    cout<<it<<" ";
	}
	return 0;
}
