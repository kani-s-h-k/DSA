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
        if(arr1[i]<=arr2[j]){
            if(temp.size()==0 || arr1[i]!=temp.back()){
                  temp.emplace_back(arr1[i]); 
            }
            i++;
        }else{
             if(temp.size()==0 || arr2[j]!=temp.back()){
                temp.emplace_back(arr2[j]);
            }
            j++;
        }
    }
    while(i<n1){
        if(temp.back()!=arr1[i])
        temp.emplace_back(arr1[i]);
        i++;
    }
    while(j<n2){
        if(temp.back()!=arr2[j])
        temp.emplace_back(arr2[j]);
        j++;
    }
    for(auto it : temp){
        cout<<it<<" ";
    }
    cout<<endl;
}
