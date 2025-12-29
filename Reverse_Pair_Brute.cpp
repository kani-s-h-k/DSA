#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    int cnt=0;
    for(int i =0;i<n;i++){
        for(int j =i+1;j<n;j++){
            if((long long)nums[i]>(2*(long long)nums[j])) cnt++;
        }
    }
    cout<<cnt<<endl;
}
