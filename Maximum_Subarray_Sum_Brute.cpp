//this brute force method doesn't pass on leetcode coz of the time exceeding

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i =0;i<n;i++){
	    cin>>arr[i];
	}
	int maxSum = INT_MIN;
    for(int i = 0;i<n;i++){
        int sum=0;
        for(int j = i;j<n;j++){
            sum+=arr[j];
            if(maxSum<sum){
                maxSum = sum;
            }
        }
    }
    cout<<maxSum<<endl;
    return 0;
}
