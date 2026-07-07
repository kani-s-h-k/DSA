class Solution {
private:
    int func(int n){
        if(n<=1) return 1;
        return func(n-1) + func(n-2);
    }
public:
    int climbStairs(int n) {
        return func(n);
    }
};