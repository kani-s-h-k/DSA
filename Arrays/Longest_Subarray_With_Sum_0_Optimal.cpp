#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i =0;i<n;i++){
	    cin>>nums[i];
	}
	long long sum = 0;
	int maxLen = 0;
	unordered_map<long long, int> mpp;
    for(int i =0;i<n;i++){
        sum+=nums[i];
        if(sum ==0){
            maxLen = max(maxLen,i+1);
        }
        else if(mpp.find(sum)!=mpp.end()){
            int len = i-mpp[sum];
            maxLen = max(maxLen,len);
        }
        else{
            mpp[sum]=i;
        }
    }
    cout<<maxLen<<endl;
    return 0;
}
