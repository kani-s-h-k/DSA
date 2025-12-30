#include <bits/stdc++.h>
using namespace std;

int main() {
	int row,col;
	cin>>row;
	cin>>col;
	vector<vector<int>> nums(row,vector<int>(col));
	for(int i =0;i<row;i++){
	    for(int j =0;j<col;j++){
	        cin>>nums[i][j];
	    }
	}
	sort(nums.begin(),nums.end());
	vector<vector<int>> ans;
	for(int i =0;i<row;i++){
	   if(ans.empty() || nums[i][0]>ans.back()[1]){
	       ans.emplace_back(nums[i]);
	   }
	   else{
	       ans.back()[1] = max(ans.back()[1], nums[i][1]);
	   }
	}
	for(auto it:ans){
	    for(auto el:it){
	        cout<<el<<" ";
	    }
	    cout<<endl;
	}

}
