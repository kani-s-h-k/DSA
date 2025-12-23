#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i =0;i<n;i++){
	    cin>>nums[i];
	}
	int k;
	cin>>k;
	int count =0;
	for(int i =0;i<n;i++){
	    for(int j =i;j<n;j++){
	        int xor1 =0;
	        for(int k =i;k<=j;k++){
	            xor1=xor1^nums[k];
	        }
             if(xor1 == k) count++;
	    }
	}
	cout<<count<<endl;
    return 0;
}