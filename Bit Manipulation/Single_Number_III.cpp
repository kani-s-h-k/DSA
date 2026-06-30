class Solution{	
	public:		
		vector<int> singleNumber(vector<int>& nums){
			int xorr = 0;
            for(auto &it: nums){
                xorr ^= it;
            }
            int b1 = 0, b2 = 0;
            int rightmost = (xorr & (xorr-1))^xorr;

            for(auto &it: nums){
                if((it & rightmost) != 0) b1 ^= it;
                else b2 ^= it;
            }
            if(b1 > b2) swap(b1, b2);
            return {b1,b2};
		}
};