#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int i = 0;
    for(int j = i+1;j<n;j++){
        if(arr[j]!=arr[i]){
            arr[i+1]= arr[j];
            i++;
        }
    }
    cout<<"No. of  Elements : "<<i+1<<endl;
    return 0;
}
