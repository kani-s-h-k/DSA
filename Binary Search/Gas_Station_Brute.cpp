class Solution {
public:
    long double minimiseMaxDistance(vector<int> &arr, int k) {
       int n = arr.size();
       vector<int> howMany(n-1,0);
       for(int i = 1;i<=k;i++){
        long double maxSection = -1, maxInd = -1;
        for(int i = 0;i<n-1;i++){
            long double diff = arr[i+1]-arr[i];
            long double sectionLength = diff/(long double)(howMany[i]+1);
            if(sectionLength> maxSection){
                maxSection = sectionLength;
                maxInd = i;
            }
        }
        howMany[maxInd]++;
       }
       long double ans = -1;
       for(int i =0;i<n-1;i++){
            long double diff = arr[i+1]-arr[i];
            long double sectionLength = diff/(long double)(howMany[i]+1);
            ans = max(ans,sectionLength);
       }
       return ans;
    }
};