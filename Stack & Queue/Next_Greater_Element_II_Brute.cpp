#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElementII(vector<int> &nums){
    vector<int> ans;
    int n = nums.size();
    for(int i =0;i<n;i++){
        bool found = false;
        for(int j=1;j<=n;j++){
            int index = (i+j)%n;
            if(nums[index]>nums[i]){
                found=true;
                ans.emplace_back(nums[index]);
                break;
            }
        }
        if(!found) ans.emplace_back(-1);
    }
    return ans;
}


int main() {
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i =0;i<n;i++){
	    cin>>nums[i];
	}
	vector<int> res = nextGreaterElementII(nums);
	for(auto it:res){
	    cout<<it<<" ";
	}
	return 0;

}
