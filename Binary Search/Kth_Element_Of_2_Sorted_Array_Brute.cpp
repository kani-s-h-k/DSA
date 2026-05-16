class Solution {
public:
    int kthElement(vector<int> &a, vector<int>& b, int k) {
        int n1 = a.size(), n2 = b.size();
        int curr = -1, i=0, j=0,count = 0;
        while(i<n1 || j<n2){
            if(j>=n2 || (i<n1 && a[i]<=b[j])){
                curr= a[i];
                i++;
            }
            else{
                curr = b[j];
                j++;
            }
            count++;
            if(count == k) break;
        }
        return curr;
  }
};