#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<long long, int> preSumMap;
    int maxLen =0;
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    long long k;
    cin>>k;
    long long sum = 0;
    for(int i =0;i<n;i++){
        sum+=arr[i];
        if(sum==k){
            if(maxLen<i+1){
                maxLen = i+1;
            }        
        }
        long long rem = sum -k;
        if(preSumMap.find(rem)!=preSumMap.end()){
            int len = i - preSumMap[rem];
            if(maxLen<len){
                maxLen=len;
            }
        }
        if(preSumMap.find(sum)==preSumMap.end()){
            preSumMap[sum] = i;
        }
    }
    cout<<maxLen<<endl;
    return 0;
}
