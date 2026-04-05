class MedianFinder {
public:
    vector<int> nums;
    MedianFinder() {
    }
    
    void addNum(int num) {
        nums.emplace_back(num);
    }
    
    double findMedian() {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n%2==1) return nums[n/2];
        else return ((double)(nums[(n-1)/2] + nums[n/2])/2);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */