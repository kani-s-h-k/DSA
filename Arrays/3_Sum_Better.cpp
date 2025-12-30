#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i=0;i<n;i++){
	    cin>>nums[i];
	}
	set<vector<int>> st;
	for(int i =0;i<n;i++){
	    set<int> hashSet;
	    for(int j =i+1;j<n;j++){
	        int third = -(nums[i]+nums[j]);
	        if(hashSet.find(third)!=hashSet.end()){
	            vector<int> temp = {nums[i],nums[j],third};
	            sort(temp.begin(),temp.end());
	            st.insert(temp);
	        }
	        hashSet.insert(nums[j]);
	    }
	}
	vector<vector<int>> ans(st.begin(),st.end());
	for(auto it:ans){
	    for(auto el:it){
	        cout<<el<<" ";
	    }
	    cout<<endl;
	}
    return 0;
}
