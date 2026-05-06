#include <bits/stdc++.h>
using namespace std;

int floorBS(vector<int> &nums, int x){
	int low = 0,  high = nums.size()-1,ans=-1;
	while(low<=high){
		int mid = low + (high-low)/2;
		if(nums[mid]<=x){
			ans = nums[mid];
			low = mid+1;
		}
		else high = mid-1;
	}
	return ans;
}

int ceilBS(vector<int> &nums, int x){
	int low = 0,  high = nums.size()-1,ans=-1;
	while(low<=high){
		int mid = low + (high-low)/2;
		if(nums[mid]>=x){
			ans = nums[mid];
			high = mid-1;
		}
		else low = mid+1;
	}
	return ans;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("E:/sublime/input.txt","r",stdin);
	freopen("E:/sublime/output.txt","w",stdout);
#endif
						//Code Starts Here
  	int n,x;
  	cin>>n;
  	vector<int> nums(n);
  	for(int i =0;i<n;i++){
  		cin>>nums[i];
  	}
  	cin>>x;
  	int fl = floorBS(nums,x);
  	int cl = ceilBS(nums,x);
  	cout<<"Floor: "<<fl<<endl<<"Ceil: "<<cl<<endl;
    return 0;
}