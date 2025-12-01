#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i =0;i<n;i++){
	    cin>>arr[i];
	}
	int xor1=0,xor2=0;
    for(int i =0;i<n;i++){
        xor1^=i;
        xor2^=arr[i];
    }
    xor1^=n;
    cout<<(xor1^xor2)<<endl;
    return 0;
}
