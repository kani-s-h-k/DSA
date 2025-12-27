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
	int i = m-1,j=0;
	while(i>=0 && j<=n){
		if(nums1[i]>nums2[j]){
			swap(nums2[j],nums1[i]);
	    	i--;
	    	j++;
		} else{
			break;
		}
	  
	}
	sort(nums1.begin(),nums1.end());
	sort(nums2.begin(),nums2.end());
    for(auto it: nums1){
        cout<<it<<" ";    
    }
    for(auto it: nums2){
        cout<<it<<" ";
    }
}
