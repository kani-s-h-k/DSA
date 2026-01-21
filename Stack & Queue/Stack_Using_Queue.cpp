#include <bits/stdc++.h>
using namespace std;

class Stack{
    private:
        queue<int> q;
    public:
        void push(int val){
            cout<<"Element Inserted: "<<val<<endl;
            int size = q.size();
            q.push(val);
            for(int i =0;i<size;i++){
                q.push(q.front());
                q.pop();
            }
        }
        
        void pop(){
            cout<<"Element Popped: "<<q.front()<<endl;
            q.pop();
        }
        
        void top(){
            cout<<q.front()<<endl;
        }
};
int main() {
	Stack st;
	st.push(5);
	st.push(7);
	st.push(9);
	st.pop();
	st.top();

}
