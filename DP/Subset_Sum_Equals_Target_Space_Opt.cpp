class Solution{
public:
    bool isSubsetSum(vector<int>arr, int target){
        if(target==0) return true;
        int n = arr.size();
        vector<bool> prev(target+1,false),cur(target+1,false);
        prev[0] = cur[0] = true;
        if(target>=arr[0]) prev[arr[0]] = true;
        for(int i= 1;i<n;i++){
            for(int j = 1;j<=target;j++){
                bool notTake = prev[j];
                bool take = false;
                if(j>=arr[i]) take = prev[j-arr[i]];
                cur[j] = take || notTake;
            }
            prev = cur;
        }
        return cur[target];
    }
};