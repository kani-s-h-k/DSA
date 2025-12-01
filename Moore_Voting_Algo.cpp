#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i =0;i<n;i++){
	    cin>>arr[i];
    }
    int count =0;
    int el;
    for(int i =0;i<n;i++){
        if(count == 0){
            count =1;
            el=arr[i];
        }
        else if(el == arr[i]){
            count ++;
        }
        else {
            count --;
        }
    }
    cout<<el<<endl;
    return 0;
}
