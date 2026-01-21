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

class Stack{
    private:
        Node* top;
        int size;
    public:
        Stack(){
            top=nullptr;
            size=0;
        }
        
        void push(int val){
            Node* newNode = new Node(val,top);
            top=newNode;
            size++;
            cout<<"Pushed Element: "<<val<<endl;
        }
        
        void pop(){
            if(top==nullptr){
                cout<<"Stack Underflow"<<endl;
                return;
            }
            cout<<"Popped Element: "<<top->data<<endl;
            Node* temp = top;
            top=top->next;
            delete temp;
            size--;
        }
        
        void peek(){
            if(top==nullptr){
                cout<<"Stack is Empty"<<endl;
                return;
            }
            cout<<"PEEK: "<<top->data<<endl;
        }
        
        void Size(){
            cout<<"Size: "<<size<<endl;
        }
        void display(){
            cout<<"Stack Elements: ";
            Node* temp = top;
            while(temp){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
        
        ~Stack(){
            while(top){
                Node* temp = top;
                top = top->next;
                delete temp;
             }
}
};

int main() {
   Stack st;
   st.push(5);
   st.push(2);
   st.push(3);
   st.push(7);
   st.push(9);
   st.pop();
   st.pop();
   st.peek();
   st.Size();
   st.display();
   return 0;
}
