#include <bits/stdc++.h>
using namespace std;

class BinaryHeap{
	public:
		int capacity;
		int size;
		int *arr;

		BinaryHeap(int cap){
			capacity = cap;
			size = 0;
			arr = new int[capacity];
		}

		int parent(int i){ 
			return (i-1)/2;
		}

		int left(int i){
			return 2*i+1;
		}

		int right(int i){
			return 2*i+2;
		}

		void insert(int x){
			if(size==capacity){
				cout<<"Binary Heap Overflow"<<endl;
				return;
			}

			arr[size]=x;
			int k = size;
			size++;

			while(k!=0 && arr[parent(k)]>arr[k]){
				swap(arr[parent(k)],arr[k]);
				k=parent(k);
			}
		}

		void heapify(int index){
			int li = left(index);
			int ri=right(index);
			int min = index;
			if(li<size && arr[li]<arr[mini]) min = li;
			if(ri<size && arr[ri]<arr[mini]) min = ri;
			if(min!=index){
				swap(arr[min],arr[index]);
				heapify(min);
			} 
		}

		int getMin(){
			if(size!=0){
				return arr[0];
			}
		}

		int extractMin(){
			if(size<=0){
				return INT_MAX;
			}
			if(size==1){
				size--;
				return arr[0];
			} 

			int mini = arr[0];
			arr[0]=arr[size-1];
			size--;

			heapify(0);
			return mini;
		}

		void display(){
			for(int i =0;i<size;i++){
				cout<<i<<" : "<<arr[i]<<endl;
			}
		}

};

int main(){

#ifndef ONLINE_JUDGE
	freopen("E:/sublime/input.txt","r",stdin);
	freopen("E:/sublime/output.txt","w",stdout);
#endif

	BinaryHeap heap(20);
	heap.insert(5);
	heap.insert(1);
	heap.insert(2);
	heap.display();
	return 0;
}