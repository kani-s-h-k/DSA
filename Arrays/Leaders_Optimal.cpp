#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i =0;i<n;i++){
	    cin>>nums[i];
	}
    vector<int> leaders;
    int maxi = INT_MIN;
    for(int i =n-1;i>=0;i--){
        if(nums[i]>maxi) leaders.insert(leaders.begin(),nums[i]);
        maxi = max(maxi, nums[i]);
    }
    for(auto it:leaders){
        cout<<it<<" ";
    }
	return 0;
}
