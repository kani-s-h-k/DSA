#include <bits/stdc++.h>
using namespace std;

int LB(vector<int> &nums,int low, int high, int target, int &ans){
    if(low>high) return ans;
    int mid = low + (high-low)/2;
    if(nums[mid]>=target){
        ans = mid;
        return LB(nums,low,mid-1,target,ans);
    } 
    else return LB(nums,mid+1,high,target,ans);
}

int UB(vector<int> &nums, int low, int high, int target, int &ans){
    if(low>high) return ans;
    int mid = low + (high-low)/2;
    if(nums[mid]>target){
        ans=mid;
        return UB(nums, low, mid-1, target, ans);
    }
    else return UB(nums,mid+1,high,target, ans);
}

int insertSearchPosition(vector<int> &nums, int target){
    int low = 0,high=nums.size()-1;
        int ans = nums.size();
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target){
                ans = mid;
                high=mid-1;
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
   vector<int> nums = {2,3,6,7,8,8,11,11,11,12};
   int ans = nums.size();
   // cout<<UB(nums,0,ans-1,10,ans);
   // int lb = lower_bound(nums.begin(),nums.end(),5)-nums.begin();
   int ub = upper_bound(nums.begin(),nums.end(),10)-nums.begin();
   cout<<ub;
    return 0;
}