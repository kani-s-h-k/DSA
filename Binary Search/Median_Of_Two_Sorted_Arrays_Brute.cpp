class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(),n2 = nums2.size();
        int size = n1+n2;
        int i = 0,j=0;
        int count=0,curr=0,prev=0;
        while(i<n1 || j<n2){
            prev = curr;
            if(j>=n2 || (i<n1 && nums1[i]<=nums2[j])){
                curr = nums1[i];
                i++;
            }
            else {
                curr = nums2[j];
                j++;
            }
            if(count == size/2) break;
            count++;
        }
        if(size%2!=0) return curr;
        else return (prev+curr)/2.0;
    }
};