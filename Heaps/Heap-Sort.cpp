#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int i, int size){
			int li = 2*i+1;
			int ri = 2*i+2;
			int maxi = i;
			if(li<size && arr[li]>arr[maxi]) maxi=li;
			if(ri<size && arr[ri]>arr[maxi]) maxi=ri;
			if(maxi!=i){
				swap(arr[maxi],arr[i]);
				heapify(arr,maxi,size);
			}
		}
int main(){

#ifndef ONLINE_JUDGE
	freopen("E:/sublime/input.txt","r",stdin);
	freopen("E:/sublime/output.txt","w",stdout);
#endif
						//Code Starts Here
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0;i<n;i++){
    	cin>>nums[i];
    }
  	for(int i = n/2-1;i>=0;i--){
  		heapify(nums,i,n);
  	}
  	for(int i = n-1;i>0;i--){
  		swap(nums[0],nums[i]);
  		heapify(nums,0,i);
  	}
  	for(auto it: nums){
  		cout<<it<<" ";
  	}
  	return 0;
}