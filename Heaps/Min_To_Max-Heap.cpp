class Solution {
    void heapify(vector<int> &nums,int i,int size){
        int li = 2*i+1;
        int ri = 2*i+2;
        int maxi = i;
        if(li<size && nums[li]>nums[maxi]) maxi = li;
        if(ri<size && nums[ri]>nums[maxi]) maxi = ri;
        if(maxi!=i){
            swap(nums[i],nums[maxi]);
            heapify(nums,maxi,size);
        }
    }
public:
    vector<int> minToMaxHeap(vector<int> nums) {
        int n =  nums.size();
        for(int i = n/2-1;i>=0;i++){
            heapify(nums,i,n);
        }
        return nums;
    }
};