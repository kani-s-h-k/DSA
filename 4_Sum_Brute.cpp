#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i =0;i<n;i++){
	    cin>>nums[i];
	}
	int target;
	cin>>target;
	vector<vector<int>> ans;
	for(int i=0;i<n;i++){
	    for(int j =i+1;j<n;j++){
	        for(int k =j+1;j<n;j++){
	            for(int h =k+1;k<n;k++){
	                if(nums[i]+nums[j]+nums[k]+nums[h]==target){
	                    vector<int> temp ={nums[i],nums[j],nums[k],nums[h]};
	                    ans.emplace_back(temp);
	                }
	            }
	        }
	    }
	}
	for(auto it: ans){
	    for(auto el: it){
	        cout<<el<<" ";
	    }
	    cout<<endl;
	}
    return 0;
}
