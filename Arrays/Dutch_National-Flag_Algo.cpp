#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i =0;i<n;i++){
	    cin>>arr[i];
	}
	int low=0,mid=0,high=n-1;
	while(mid<=high){
	    if(arr[mid] == 0){
	        swap(arr[mid],arr[low]);
	        mid++;
	        low++;
	    }
	    else if(arr[mid] == 1) mid++;
	    else {
	        swap(arr[mid],arr[high]);
	        high--;
	    }
	}
    return 0;
}
