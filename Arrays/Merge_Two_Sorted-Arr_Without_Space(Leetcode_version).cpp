#include <bits/stdc++.h>
using namespace std;

int main() {
	int m,n;
	cin>>m;
	vector<int> nums1(m);
	for(int i =0;i<m;i++){
	    cin>>nums1[i];
	}
	cin>>n;
	vector<int> nums2(n);
	for(int i =0;i<n;i++){
	    cin>>nums2[i];
	}
	for(int i = m;i<n+m;i++){
	    nums1.emplace_back(nums2[i-m]);
	}
	sort(nums1.begin(),nums1.end());
    for(auto it: nums1){
        cout<<it<<" ";    
    }
}
