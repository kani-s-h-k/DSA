class Solution {
  public:
    int LongestBitonicSequence(vector<int> arr) {
            int n = arr.size();
            vector<int> dp1(n,1),dp2(n,1),bitonic;
            for(int i = 0;i<n;i++){
                for(int j = 0;j<=i-1;j++){
                    if(arr[i]>arr[j] && 1 + dp1[j]>dp1[i]){
                        dp1[i] = 1 + dp1[j];
                    }
                }
            }
            for(int i = n-1;i>=0;i--){
                for(int j = n-1;j>=i+1;j--){
                    if(arr[i]>arr[j] && 1+ dp2[j]>dp2[i]){
                        dp2[i] = 1 + dp2[j];
                    }
                }
            }
            for(int i =0;i<n;i++){
                bitonic.emplace_back(dp1[i] + dp2[i] - 1);
            }
            return *max_element(bitonic.begin(),bitonic.end());
    }
};
