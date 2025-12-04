#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i =0;i<n;i++){
	    cin>>nums[i];
	}
	if(n==0) return 0;
	sort(nums.begin(),nums.end());
	int count =0,longest = 1,last_num = INT_MIN;
	for(int i =0;i<n;i++){
	    if(nums[i]-1 ==last_num){
	        count++;
	        last_num=nums[i];
	    } else if(nums[i] != last_num){
	        count = 1;
	        last_num=nums[i];
	    }
	    longest = max(longest,count);
	}
	cout<<longest<<endl;
	return 0;
}
