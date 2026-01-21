#include <bits/stdc++.h>
using namespace std;

class Queue{
    private:
        stack<int> s1,s2;
    public:
        void push(int val){
            cout<<"Inserted Element: "<<val<<endl;
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(val);
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
        
        void pop(){
            if(s1.empty()){
                cout<<"Stack Underflow"<<endl;
                return;
            }
            cout<<"Deleted Element: "<<s1.top()<<endl;
            s1.pop();
        }
        
        void top(){
            cout<<"Top: "<<s1.top()<<endl;
        }
};
int main() {
	Queue q;
	q.push(3);
	q.push(5);
	q.push(7);
	q.push(9);
	q.pop();
	q.top();

}
