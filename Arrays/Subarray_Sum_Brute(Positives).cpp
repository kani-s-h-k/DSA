#include <bits/stdc++.h>
using namespace std;

int main() {
    int len = 0;
	int n;
	cin>>n;
	int arr[n];
	for(int i =0;i<n;i++){
	    cin>>arr[i];
	}
	int k;
	cin>>k;
	for(int i =0;i<n;i++){
	     int sum =0;
	    for(int j = i;j<n;j++){
	       sum+=arr[j];
	        if(sum == k){
	            if(len<j-i+1){
	                len = j-i+1;
	            }
	            break;
	        }
	    }
	}
	cout<<len<<endl;
	return 0;
}
