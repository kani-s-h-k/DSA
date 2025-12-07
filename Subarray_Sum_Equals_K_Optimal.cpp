#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i =0;i<n;i++){
	    cin>>nums[i];
	}
	int k;
	cin>>k;
    unordered_map<int,int> mpp;
    mpp[0]=1;
    int preSum = 0,count=0;
    for(int i =0;i<nums.size();i++){
        preSum+=nums[i];
        int remove =  preSum - k;
        count+=mpp[remove];
        mpp[preSum] +=1;
    }
    cout<<count<<endl;
    return 0;
}
