#include <bits/stdc++.h>
using namespace std;

bool ls(vector<int> nums, int x){
    for(int i =0;i<nums.size();i++){
        if(nums[i] == x) return true;
    }
    return false;
}
int main() {
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i =0;i<n;i++){
	    cin>>nums[i];
	}
	int longest = 1;
	for(int i=0;i<n;i++){
	    int count = 1;
	    int x  = nums[i];
	    while(ls(nums,x+1)){
	        count++;
	        x=x+1;
	    }
	    longest = max(longest,count);
	}
	cout<<longest;
	return 0;
}
