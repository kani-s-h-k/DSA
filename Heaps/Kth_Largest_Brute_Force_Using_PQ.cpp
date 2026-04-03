#include <bits/stdc++.h>
using namespace std;

int main(){

#ifndef ONLINE_JUDGE
	freopen("E:/sublime/input.txt","r",stdin);
	freopen("E:/sublime/output.txt","w",stdout);
#endif
						//Code Starts Here
int n,k;
cin>>n;
vector<int> nums(n);
for(int i =0;i<n;i++){
	cin>>nums[i];
}
cin>>k;
priority_queue<int,vector<int>,greater<int>> pq;
for(int i =0;i<k;i++){
	pq.push(nums[i]);
}
for(int i = k;i<n;i++){
	if(nums[i]>pq.top()){
		pq.pop();
		pq.push(nums[i]);
	}
}
cout<<pq.top()<<endl;
return 0;
}
