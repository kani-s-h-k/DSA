#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &nums, int low, int mid, int high){
    int inv =0;
    int left = low;
    int right = mid+1;
    vector<int> temp;
    while(left<=mid && right<=high){
        if(nums[left]<=nums[right]){
            temp.emplace_back(nums[left]);
            left++;
        }else{
            temp.emplace_back(nums[right]);
            inv+=(mid-left+1);
            right++;
        }
    }
    while(left<=mid){
        temp.emplace_back(nums[left]);
        left++;
    }
    while(right<=high){
        temp.emplace_back(nums[right]);
        right++;
    }
    for(int i = low;i<=high;i++){
        nums[i] = temp[i-low];
    }
    return inv;
}
int mergeSort(vector<int> &nums, int low, int high){
    if(low>=high) return 0;
    int inv = 0;
    int mid = (low+high)/2;
    inv+=mergeSort(nums,low,mid);
    inv+=mergeSort(nums,mid+1,high);
    inv+= merge(nums,low,mid,high);
   return inv;
}
int main() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    int inv = mergeSort(nums, 0, n-1);
    for(auto it: nums){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<inv<<" ";
    return 0;
}
