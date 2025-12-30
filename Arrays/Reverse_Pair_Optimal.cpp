#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int low, int mid, int high){
    int inv =0;
    int left = low;
    int right = mid+1;
    vector<int> temp;
    while(left<=mid && right<=high){
        if(nums[left]<nums[right]){
            temp.emplace_back(nums[left]);
            left++;
        }else{
            temp.emplace_back(nums[right]);
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
}
int countPairs(vector<int> &nums, int low, int mid, int high){
    int cnt =0;
    int right = mid+1;
    for(int i = low;i<=mid;i++){
        while(right<=high && ((long long)nums[i]>(2*(long long)nums[right]))){
            right++;
        }
        cnt+=right-(mid+1);
    }
    return cnt;
}
int mergeSort(vector<int> &nums, int low, int high){
    int cnt =0;
    if(low>=high) return 0;
    int mid = (low+high)/2;
    cnt+=mergeSort(nums,low,mid);
    cnt+=mergeSort(nums,mid+1,high);
    cnt+=countPairs(nums,low,mid,high);
    merge(nums,low,mid,high);
   return cnt;
}
int main() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    int cnt = mergeSort(nums, 0, n-1);
    for(auto it: nums){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<cnt<<endl;
    return 0;
}
