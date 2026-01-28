#include <bits/stdc++.h>
using namespace std;


int sumSubMin(vector<int> &nums){
    int n = nums.size();
    int miniSum=0;
    int mod = (int)1e9+7;
    for(int i = 0;i<n;i++){
        int mini =INT_MAX;
        for(int j = i;j<n;j++){
            mini=min(mini,nums[j]);
            miniSum=(miniSum+mini)%mod;
        }
    }
    return miniSum;
}

int main() {
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i =0;i<n;i++){
	    cin>>nums[i];
	}
	cout<<sumSubMin(nums);
    return 0;
}
