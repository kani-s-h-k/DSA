#include <bits/stdc++.h>
using namespace std;

class Queue{
    private:
        stack<int> s1,s2;
    public:
        void push(int val){
            cout<<"Element Pushed: "<<val<<endl;
            s1.push(val);
        }
        void pop(){
            if(!s2.empty()) s2.pop();
            else{
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
                cout<<"Deleted Element: "<<s2.top()<<endl;
                s2.pop();
            }
        }
        void top(){
            if(!s2.empty()) cout<<"Top: "<< s2.top();
            else{
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
                cout<<"Top: "<<s2.top()<<endl;
            }
        }
};

int main() {
	Queue q;
	q.push(2);
	q.push(4);
	q.push(6);
	q.push(8);
	q.pop();
	q.top();
    return 0;
}
