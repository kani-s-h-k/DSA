#include <bits/stdc++.h>
using namespace std;

class CirclularQueue{
    private:
        int capacity;
        int* cqueue;
        int front,rear;
        int size=0;
    public:
        CirclularQueue(int SIZE){
            front=-1, rear=-1;
            capacity=SIZE;
            cqueue = new int[capacity];
        }
        
        void enqueue(int val){
            if(size==capacity){
                cout<<"Queue Overflow"<<endl;
                return;
            }
            cout<<"Inserted Element: "<<val<<endl;
            if(front == -1){
               front=0; rear=0; 
            }
            else{
                rear=(rear+1)%capacity;
            }
            cqueue[rear] = val;
            size++;
        }
        
        void dequeue(){
            if(size==0) {
                cout<<"Queue Underflow"<<endl;
                return;
            }
            cout<<"Deleted Element: "<<cqueue[front]<<endl;
            if(size==1){
                front=-1;
                rear=-1;
            }
            else{
                front=(front+1)%capacity;
            }
            size--;
        }
        
        void SIZE(){
            cout<<"SIZE:" <<size<<endl;
        }
        
        void display(){
            if(size==0){
                cout<<"Queue is Empty"<<endl;
                return;
            }
            cout<<"Queue Elements: ";
            int i = front;
            for(int cnt = 0;cnt<size;cnt++){
                cout<<cqueue[i]<<" ";
                i=(i+1)%capacity;
            }
        }
        
        ~CirclularQueue(){
            delete[] cqueue;
        }
};

int main() {
    int n;
    cin>>n;
    CirclularQueue cq(n);
    cq.enqueue(3);
    cq.enqueue(5);
    cq.enqueue(4);
    cq.enqueue(9);
    cq.dequeue();
    cq.SIZE();
    cq.display();
    return 0;
}
