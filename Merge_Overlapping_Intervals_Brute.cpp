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
	    if(!ans.empty() && nums[i][1]<=ans.back()[1]) continue;
	    int start = nums[i][0];
	    int end = nums[i][1];
	    for(int j = i+1;j<row;j++){
	        if(nums[j][0]<=end) end = max(end,nums[j][1]);
	        else break;
	    }
	    vector<int> temp={start,end};
	    ans.emplace_back(temp);
	}
	for(auto it:ans){
	    for(auto el:it){
	        cout<<el<<" ";
	    }
	    cout<<endl;
	}

}
