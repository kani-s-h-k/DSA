#include <bits/stdc++.h>
using namespace std;

 void heapify(vector<int> &arr, int size, int i){
        int li = 2*i+1;
        int ri = 2*i+2;
        int maxi = i;
        if(li<size && arr[li]>arr[maxi]) maxi=li;
        if(ri<size && arr[ri]>arr[maxi]) maxi=ri;
        if(maxi!=i){
            swap(arr[maxi],arr[i]);
            heapify(arr,size,maxi);
        }
    }
void extractMax(vector<int> &arr,int &size){
        swap(arr[0],arr[size-1]);
        size--;
        heapify(arr,size,0);
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("E:/sublime/input.txt","r",stdin);
	freopen("E:/sublime/output.txt","w",stdout);
#endif
						//Code Starts Here
	int n,k;
	cin>>n;
	vector<int> nums(n);
	for(int i = 0;i<n;i++){
		cin>>nums[i];
	}
	cin>>k;
	for(int i = n/2-1;i>=0;i--){
            heapify(nums,n,i);
    }
    int size  = n;
    for(int i = 0;i<k-1;i++){
        extractMax(nums,size);
    }
    cout<<nums[0]<<endl;
	return 0;
}