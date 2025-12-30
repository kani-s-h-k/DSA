#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i =0;i<n;i++){
	    cin>>nums[i];
	}
	int target;
	cin>>target;
    set<vector<int>> st;
    for(int i =0;i<n;i++){
        for(int j =i+1;j<n;j++){
            set<long long> hashSet;
            for(int k =j+1;k<n;k++){
               long long fourth = (long long)target - ((long long)nums[i]+nums[j]+nums[k]);
               if(hashSet.find(fourth)!=hashSet.end()){
                   vector<int> temp = {nums[i],nums[j],nums[k],(int)fourth};
                   st.insert(temp);
               }
               hashSet.insert(nums[k]);
            }
        }
    }
    for(auto it: st){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
