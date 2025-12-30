#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> temp;
	int n1,n2;
	cin>>n1;
	cin>>n2;
	int arr1[n1];
	int arr2[n2];
	for(int i =0;i<n1;i++){
	    cin>>arr1[i];
	}
	for(int i =0;i<n2;i++){
	    cin>>arr2[i];
	}
    int i = 0,j = 0;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            i++;
        }
        else if(arr2[j]<arr1[i]){
            j++;
        }
        else{
            temp.emplace_back(arr1[i]);
            i++;
            j++;
        }
    }
   
    for(auto it : temp){
        cout<<it<<" ";
    }
    cout<<endl;
}
