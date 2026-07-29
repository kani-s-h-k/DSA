#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
   int countPartitions(int n, int diff, vector<int>& arr) {
        int total_sum = accumulate(arr.begin(),arr.end(),0);
        if((total_sum - diff)<0 || (total_sum - diff)%2==1) return 0;
        int target  = (total_sum - diff)/2;
        vector<int> prev(target+1,0),curr(target+1,0);
        prev[0]=1;
        if(arr[0]==0) prev[0]=2;
        else if(arr[0]!=0 && target>=arr[0]) prev[arr[0]] =1;
        for(int i= 1;i<n;i++){
            for(int j=0;j<=target;j++){
                int notTake = prev[j];
                int take = 0;
                if(j>=arr[i]) take = prev[j-arr[i]];
                curr[j] = (take + notTake)%1e9+7;
            }
            prev = curr;
        }
        return prev[target]%1e9+7;
    }
};