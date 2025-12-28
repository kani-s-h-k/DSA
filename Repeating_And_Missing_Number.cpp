#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i =0;i<n;i++){
	    cin>>nums[i];
	}
	int s=0;
	int sn = (n*(n+1))/2;
	for(int i =0;i<n;i++){
	    s+=nums[i];
	}
	int dif = s - sn;
	int sqn = (n*(n+1)*((2*n)+1))/6;
	int sq=0;
	for(int i =0;i<n;i++){
	    sq+=nums[i]*nums[i];
	}
	int sqdif = sq - sqn;
	int add = sqdif/dif;
	int x = (dif+add)/2;
	int y = add-x;
	cout<<x<<" "<<y<<endl;
    return 0;
}
