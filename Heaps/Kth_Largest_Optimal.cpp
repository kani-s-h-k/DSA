#include <bits/stdc++.h>
using namespace std;

int randomIndex(int left, int right){
	int len = right-left+1;
	return (rand()%len)+left;
}

int func(vector<int> &nums, int pivotIndex, int left, int right){
	int pivot=nums[pivotIndex];
	swap(nums[pivotIndex],nums[left]);
	int i = left+1,j=right;
	while(i<=j){
		while(i<=right && pivot<nums[i] ){
			i++;
		}
		while(j>=left && pivot>=nums[j] ){
			j--;
		}
		if(i<j){
			swap(nums[i],nums[j]);
		}
	}
	swap(nums[left],nums[j]);
	return j;
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
for(int i =0;i<n;i++){
	cin>>nums[i];
}
cin>>k;
if(k>n) return 0;

int left = 0,right=n-1;
while(true){
	int pivotIndex = randomIndex(left,right);
	pivotIndex=func(nums,pivotIndex,left,right);
	if(pivotIndex == k-1){
		cout<<nums[pivotIndex]<<endl;
		break;
	}
	else if(pivotIndex>k-1) right=pivotIndex-1;
	else left = pivotIndex+1;
}
return 0;
}
