class MinStack {
private:
    stack<long long> st;
    long long min;
public:
    MinStack() {
        min = LONG_MAX;
    }
    
    void push(int val) {
       if(st.empty()){
        min = val;
        st.push(val);
       }
       else{
        if(val>min) st.push(val);
        else{
            long long m = (2LL*val) - min;
            st.push(m);
            min=val;
        }
       }
    }
    
    void pop() {
        long long x = st.top();
        st.pop();
        if(x<min){
            min=2*min-x;
        }
    }
    
    int top() {
        long long x = st.top();
        if(x<min) return min;
        else return x;
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */