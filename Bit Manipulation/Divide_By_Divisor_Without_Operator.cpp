class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        bool sign = true;
        
        if(dividend>=0 && divisor <0) sign = false;
        if(dividend<0 && divisor>0) sign = false;
        if(divisor == 1) return dividend;

        long long n = llabs((long long)dividend), d = llabs((long long)divisor);
        long long ans = 0;
        while(n >= d){
            int count = 0;
            while(n >= (d<<(count+1))) count++;
            ans += (1LL<<count);
            n -= d * (1LL<<count);
        }

        if(ans > (1LL<<31) && sign == false) return INT_MIN;
        if(ans >= (1LL<<31) && sign == true) return INT_MAX;

        return sign ? (int)ans : -(int)ans;
    }
};