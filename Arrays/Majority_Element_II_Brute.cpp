#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i =0;i<n;i++){
	    cin>>nums[i];
	}
	vector<int> major;
	for(int i =0;i<n;i++){
	    int count =0;
	    if(major.size()==0 || major[0]!=nums[i]){
	        for(int j =0;j<n;j++){
	            if(nums[j]==nums[i]) count++;
	        }
	        if(count>n/3) major.emplace_back(nums[i]);
	    }
	    if(major.size()==2) break;
	}
	for(auto it:major){
	    cout<<it<<" "; 
	}
	return 0;
}
