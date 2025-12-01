#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i =0;i<n;i++){
	    cin>>arr[i];
	}
    int sum = (n*(n+1))/2;
    int arrSum = 0;
    for(int i =0;i<n;i++){
        arrSum+=arr[i];
    }
    if(arrSum==sum){
        cout<<0<<endl;
    }
    else{
        cout<<sum-arrSum<<endl;
    }
    return 0;
}
