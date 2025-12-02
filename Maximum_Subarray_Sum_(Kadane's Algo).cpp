#include <bits/stdc++.h>
using namespace std;

int main() {
    int ansStart=-1,ansEnd=-1,start=-1;
	int n;
	cin>>n;
	int arr[n];
	for(int i =0;i<n;i++){
	    cin>>arr[i];
	}
	int maxSum = INT_MIN;
	int sum = 0;
    for(int i =0;i<n;i++){
        if(sum == 0)  start = i;
        sum+=arr[i];
        if(maxSum<sum) {
            maxSum=sum;
            ansStart =start;
            ansEnd = i;
        }
        if(sum<0){
            sum=0;
        }
    }
    cout<<maxSum<<endl;
    cout<<ansStart<<" "<<ansEnd<<endl;
    return 0;
}
