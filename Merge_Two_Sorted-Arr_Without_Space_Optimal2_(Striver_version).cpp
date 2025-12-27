#include <bits/stdc++.h>
using namespace std;

void swapArr(vector<int>&arr1,vector<int>&arr2,int ind1,int ind2){
    if(arr1[ind1]>arr2[ind2]) swap(arr1[ind1],arr2[ind2]);
}
int main() {
	int m,n;
	cin>>m;
	vector<int> nums1(m);
	for(int i =0;i<m;i++){
	    cin>>nums1[i];
	}
	cin>>n;
	vector<int> nums2(n);
	for(int i =0;i<n;i++){
	    cin>>nums2[i];
	}

    int len = n+m;
    int gap = (len/2)+(len%2);
    while(gap>0){
        int left = 0;
        int right = left+gap;
        while(right<len){
        //nums1 and nums2
        if(left<m && right>=m){
            swapArr(nums1,nums2,left,right-m);
        }
        //both on nums2
        else if(left>=m){
            swapArr(nums2,nums2,left-m,right-m);
        }
        //both on nums1
        else{
            swapArr(nums1,nums1,left,right);
        }
        left++;
        right++;
    }
        if(gap==1) break;
        gap = (gap/2)+(gap%2);
    }
    for(auto it: nums1){
        cout<<it<<" ";
    }
    for(auto it : nums2){
        cout<<it<<" ";
    }
}
