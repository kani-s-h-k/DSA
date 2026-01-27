#include <bits/stdc++.h>
using namespace std;

int trappingRainwater(vector<int> height, vector<int> prefixMax, vector<int> suffixMax){
    int n = height.size();
    int total = 0;
    for(int i =0;i<n;i++){
        int leftMax=prefixMax[i];
        int rightMax=suffixMax[i];
        if(height[i]<leftMax && height[i]<rightMax){
            total+=min(leftMax,rightMax)-height[i];
        }
    }
    return total;
}

void findPrefixMax(vector<int> height, vector<int> &prefixMax){
    int n = height.size();
    prefixMax[0]=height[0];
    for(int i =1;i<n;i++){
        prefixMax[i]=max(prefixMax[i-1],height[i]);
    }
}

void findSuffixMax(vector<int> height, vector<int> &suffixMax){
    int n = height.size();
    suffixMax[n-1]=height[n-1];
    for(int i =n-2;i>=0;i--){
        suffixMax[i]=max(suffixMax[i+1],height[i]);
    }
}

int main() {
	int n;
	cin>>n;
	vector<int> height(n);
	for(int i =0;i<n;i++){
	    cin>>height[i];
	}
	vector<int> prefixMax(n);
	vector<int> suffixMax(n);
	findPrefixMax(height, prefixMax);
	findSuffixMax(height, suffixMax);
	cout<<trappingRainwater(height,prefixMax,suffixMax)<<endl;
	return 0;
}
