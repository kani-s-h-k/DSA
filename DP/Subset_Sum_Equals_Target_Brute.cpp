class Solution{
private:
    bool func(int ind, vector<int> &arr, int target){
        if(target==0) return true;
        if(ind==0) return arr[ind] == target;

        bool notTake = func(ind-1, arr, target);
        bool take = false;
        if(target>=arr[ind])
            take = func(ind-1, arr, target-arr[ind]);

        return take || notTake;
    }

public:
    bool isSubsetSum(vector<int> arr, int target){
        if(target==0) return true;
        int n = arr.size();
        return func(n-1, arr, target);
    }
};