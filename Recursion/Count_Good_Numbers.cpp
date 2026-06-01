class Solution {
    const int MOD = 1e9+7;
    long long helper(long long base, long long expo){
        long long ans = 1;
        while(expo>0){
            if(expo%2==0){
                base=(base*base)%MOD;
                expo/=2;
            }
            else{
                ans = (ans*base)%MOD;
                expo-=1;
            }
        }
        return ans;
    }
public:
    int countGoodNumbers(long long n) {
        if(n==1) return 5;
        long long even = (n+1)/2;
        long long odd = n/2;
        return (int)((helper(5,even) * helper(4,odd))%MOD);
    }
};