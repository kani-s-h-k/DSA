#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i =0;i<n;i++){
	    cin>>nums[i];
	}
	if(n==0) return 0;
	unordered_set<int> st;
	int longest = 1;
	for(int i =0;i<n;i++){
	    st.insert(nums[i]);
	}
	for(auto num: st){
	    int count = 1;
	    if(!st.contains(num-1)){
	        while(st.contains(num+1)){
	                count++;
	                num++;
	        }
	    }
	    longest=max(longest,count);
	}
	cout<<longest<<endl;
	return 0;
}
