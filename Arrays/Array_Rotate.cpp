#include <bits/stdc++.h>
using namespace std;
void print(int arr[], int n){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void reverse(int (&arr)[], int start, int end){
    while(start<=end){
        int temp = arr[start];
        arr[start]= arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    char ch;
    cin>>ch;
    if(ch == 'l'){
        reverse(arr,n-k,n-1);
        reverse(arr,0,n-k-1);
        reverse(arr,0,n-1);
    }else if(ch=='r'){
        reverse(arr,0,k-1);
        reverse(arr,k,n-1);
        reverse(arr,0,n-1);
    }else{
        cout<<"Invalid Input"<<endl;
        return 0;
    }
    print(arr,n);
    return 0;
}
