#include <bits/stdc++.h>
using namespace std;

int closest_pair_split(vector<int> &nums, int low, int mid, int high){
    int dist = nums[mid+1]-nums[mid];
    return dist;
}
int closest_pair(vector<int> &nums,int low,int high){
    if(low==high) return INT_MAX;
    if(high-low ==1) return nums[high]-nums[low];
    int mid = low+ (high-low)/2;
    int left =closest_pair(nums,low,mid);
    int right = closest_pair(nums,mid+1,high);
    int cross = closest_pair_split(nums,low,mid,high);
    return min({left,right,cross});
}

int main() {
	vector<int> nums = {8, 3, 8, 10};
	sort(nums.begin(),nums.end());
	cout<<closest_pair(nums,0,nums.size()-1)<<endl;
    return 0;
}
