class Solution {
public:
    bool checkIthBit(int n, int i) {
        //Using left shift operator
        // if((n & (1<<i)) !=0) return true;
        // return false;

        //Using right shift operator
        if(((n>>i) & 1)!=0) return true;
        return false;

    }
};