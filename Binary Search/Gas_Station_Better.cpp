class Solution {
public:
    long double minimiseMaxDistance(vector<int> &arr, int k) {
       int n = arr.size();
       vector<int> howMany(n-1,0);
       priority_queue<pair<long double, int>> pq;
       for(int i =0;i<n-1;i++){
            pq.push({arr[i+1]-arr[i],i});
       }
       for(int i = 1;i<=k;i++){
            auto top = pq.top();
            pq.pop();
            int secInd = top.second;
            howMany[secInd]++;
            long double iniDiff = arr[secInd+1]-arr[secInd];
            long double newSec = iniDiff/(long double)(howMany[secInd]+1);
            pq.push({newSec,secInd});
       }
       return pq.top().first;
    }
};