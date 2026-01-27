#include <bits/stdc++.h>
using namespace std;

int trappingRainwater(vector<int> height){
    int n = height.size();
    int lmax = 0,rmax=0,total=0,l=0,r=n-1;
    while(l<r){
        if(height[l]<=height[r]){
            if(lmax>height[l])
                total+=lmax-height[l];
            else
                lmax=height[l];
            l++;
        }
        else{
            if(rmax>height[r])
                total+=rmax-height[r];
            else
                rmax=height[r];
            r--;
        }
    }
    return total;
}



int main() {
	int n;
	cin>>n;
	vector<int> height(n);
	for(int i =0;i<n;i++){
	    cin>>height[i];
	}
	cout<<trappingRainwater(height)<<endl;
	return 0;
}
