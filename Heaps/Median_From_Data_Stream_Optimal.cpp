#include <bits/stdc++.h>
using namespace std;


class MedianFinder{
    public:
        priority_queue<int> maxHeap;
        priority_queue<int,vector<int>,greater<int>> minHeap;

        void addNum(int n){
            maxHeap.push(n);
            minHeap.push(maxHeap.top());
            maxHeap.pop();

            if(minHeap.size()>maxHeap.size()){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }

        double findMedian(){
            if(maxHeap.size()==minHeap.size()){
                return (maxHeap.top()+minHeap.top())/2.0;
            }
            else return maxHeap.top();
        }

};

int main(){

#ifndef ONLINE_JUDGE
	freopen("E:/sublime/input.txt","r",stdin);
	freopen("E:/sublime/output.txt","w",stdout);
#endif
						
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << mf.findMedian() << endl; 
    mf.addNum(3);
    cout << mf.findMedian() << endl; 
    return 0;
}