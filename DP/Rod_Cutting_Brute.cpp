class Solution {
  private:
    int func(int ind, int N,vector<int> &price){
        if(ind==0){
            return N*price[0];
        }
        int notTake = func(ind-1,N,price);
        int take = INT_MIN;
        int rodLength = ind + 1;
        if(N>=rodLength) take  = price[ind] + func(ind,N-rodLength,price);
        return max(take,notTake);
    }
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        return func(n-1,n,price);
        
    }
};