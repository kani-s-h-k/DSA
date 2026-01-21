#include <bits/stdc++.h>
using namespace std;

class Stack{
    private:
        int stack[100];
        int n = 100;
        int top;
    
    public:
        Stack(){
            top = -1;
        }
        
        void push(int val){
            if(top==n-1){
                cout<<"Stack Overflow!"<<endl;
            }
            else{
                cout<<"Pushed Element: "<<val<<endl;
                stack[++top]=val;
            }
        }
        
        void pop(){
            if(top==-1){
                cout<<"Stack Underflow"<<endl;
            }
            else{
                cout<<"Popped Element: "<<stack[top]<<endl;
                top--;
            }
        }
        
        void peek(){
            if(top==-1) cout<<"Stack is Empty!"<<endl;
            else cout<<stack[top]<<endl;
        }
        
        int size(){
            return top+1;
        }
        
        void display(){
            if(top==-1) cout<<"Stack is Empty!"<<endl;
            else{
                cout<<"Stack Elements: ";
                for(int i = top;i>=0;i--){
                    cout<<stack[i]<<" ";
                }
            }
        }
        
};

int main() {
	Stack st;
	st.push(5);
	st.push(2);
	st.push(1);
	st.push(9);
	st.push(7);
	st.pop();
	st.pop();
	st.pop();
	st.pop();
	st.pop();
	st.pop();
	st.display();

}
