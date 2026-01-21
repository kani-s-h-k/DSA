#include <bits/stdc++.h>
using namespace std;

class Queue{
    private:
        int queue[100];
        int SIZE = 100;
        int front,rear;
    public:
        Queue(){
            front =-1;
            rear=-1;
        }
        
        void enqueue(int val){
            if(rear==SIZE-1) cout<<"Queue Overflow"<<endl;
            else{
                cout<<"Inserted Element: "<<val<<endl;
                if(front==-1) front =0;
                queue[++rear]=val;
            }
        }
        
        void dequeue(){
            if(front == -1){
               cout<<"Queue Underflow"<<endl;
               return;
            }
            cout<<"Deleted Element: "<<queue[front]<<endl;
            if(front == rear){
                front =-1;
                rear = -1;
            }
            else{
                front++;
            }
        }
        
        void size(){
            if(front==-1) cout<<"Queue  is empty"<<endl;
            else cout<<"Size: "<<rear-front+1<<endl;
        }
        
        void display(){
            if(front ==-1){
                cout<<"Queue  is Empty"<<endl;
                return;
            }
            cout<<"Queue Elements: ";
            for(int i = front;i<=rear;i++){
                cout<<queue[i]<<" ";
            }
        }
};

int main() {
    Queue q;
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(6);
    q.enqueue(8);
    q.dequeue();
    q.dequeue();
    q.size();
    q.display();

}
