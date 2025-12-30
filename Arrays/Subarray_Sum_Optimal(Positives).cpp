#include <bits/stdc++.h>
using namespace std;

int main() {
    int maxLen =0;
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    long long k;
    cin>>k;
    long long sum = arr[0];
    int left = 0;
    int right = 0;
    while(right<n){
        while(left<=right && sum>k){
            sum-=arr[left];
            left++;
        }
        if(sum == k){
            if(maxLen<right - left + 1){
                maxLen = right - left + 1;
            }
        }
        right ++;
        if(right<n) sum+=arr[right];
    }
    
    cout<<maxLen<<endl;
    return 0;
}
