#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &nums2,int el){
    for(int i =0;i<nums2.size();i++){
        if(el==nums2[i]) return i+1;
    }
    return INT_MAX;
}
vector<int> nextGreatestElement(vector<int> &nums1,vector<int> &nums2){
    vector<int> ans;
    int n1 = nums1.size();
    int n2 = nums2.size();
    for(int i =0;i<n1;i++){
        int j = find(nums2,nums1[i]);
        bool found = false;
        for(j;j<n2;j++){
            if(nums2[j]>nums1[i]){
                ans.emplace_back(nums2[j]);
                found = true;
                break;
            }
        }
        if(!found){
            ans.emplace_back(-1);
        }
    }
    return ans;
}
int main() {
	int n1,n2;
	cin>>n1;
	vector<int> nums1(n1);
	for(int i =0;i<n1;i++){
	    cin>>nums1[i];
	}
	cin>>n2;
	vector<int> nums2(n2);
	for(int i =0;i<n2;i++){
	    cin>>nums2[i];
	}
    vector<int> ans = nextGreatestElement(nums1,nums2);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}
