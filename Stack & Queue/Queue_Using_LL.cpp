#include <bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* next;
  
  Node(int data1){
      data=data1;
      next=nullptr;
  }
  
  Node(int data1, Node* next1){
      data=data1;
      next=next1;
  }
  
};

class Queue{
    private:
        Node* front, *rear;
        int size;
    public:
    Queue(){
        front=nullptr;
        rear=nullptr;
        size=0;
    }
    
    void enqueue(int val){
        Node* newNode = new Node(val);
        if(front==nullptr){
            front = newNode;
            rear = front;
        }
        else{
            rear->next = newNode;
            rear=newNode;
        }
        cout<<"Inserted Element: "<<val<<endl;
        size++;
    }
    
    void dequeue(){
        if(front == nullptr){
            cout<<"Queue Underflow!"<<endl;
            return;
        }
        cout<<"Deleted Element: "<<front->data<<endl;
        Node* temp = front;
        front = front->next;
        delete temp;
        if(front==nullptr) rear=nullptr;
        size--;
    }
    
    void Size(){
        cout<<"Size: "<<size<<endl;
    }
    
    
    void display(){
        if(front == nullptr){
            cout<<"Queue is Empty!"<<endl;
            return;
        }
        Node* temp = front;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    
    ~Queue(){
        while(front){
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
   Queue q;
   q.enqueue(5);
   q.enqueue(7);
   q.enqueue(9);
   q.enqueue(1);
   q.dequeue();
   q.display();
}
