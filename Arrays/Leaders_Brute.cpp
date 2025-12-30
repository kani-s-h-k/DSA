#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i =0;i<n;i++){
	    cin>>nums[i];
	}
    vector<int> leaders;
    for(int i =0;i<n;i++){
        bool isLeader = true;
        for(int j = i+1;j<n;j++){
            if(nums[i]<nums[j]){
                isLeader = false;
                break;
            }
        }
        if(isLeader) leaders.emplace_back(nums[i]);
    }
    for(auto it:leaders){
        cout<<it<<" ";
    }
	return 0;
}
