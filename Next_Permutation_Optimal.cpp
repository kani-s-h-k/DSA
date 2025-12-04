#include <bits/stdc++.h>
using namespace std;
void reverse(vector<int> &nums,int start, int end){
    while(start<=end){
        swap(nums[start],nums[end]);
        start++;
        end--;
    }
}
int main() {
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i =0;i<n;i++){
	    cin>>nums[i];
	}
    int index = -1;
    for(int i =n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            index = i;
            break;
        }
    }
    if(index == -1){
        reverse(nums,0,n-1);
        for(auto it : nums){
            cout<<it<<" ";
        }
        return 0;
    }
    for(int i = n-1;i>=index;i--){
        if(nums[i]>nums[index]){
            swap(nums[index],nums[i]);
            break;
        }
    }
    reverse(nums,index+1,n-1);
    for(auto it: nums){
        cout<<it<<" ";
    }
	return 0;
}
