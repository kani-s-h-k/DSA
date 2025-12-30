#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int,int> mpp;
	int n;
	cin>>n;
	int arr[n];
	for(int i =0;i<n;i++){
	    cin>>arr[i];
	}
	int target;
	cin>>target;
	for(int i =0;i<n;i++){
	    if(mpp.find(target - arr[i])!=mpp.end()){
	        cout<<mpp[target - arr[i]]<<" "<<i<<endl;
	        return 0;
	    }
	    mpp[arr[i]] = i;
	}
    return 0;
}
