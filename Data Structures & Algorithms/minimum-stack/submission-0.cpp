class MinStack {
private:
    stack<int> st;
    stack<int> minSt;

// O(1) time for all operations / O(n) space 
public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);

        if(minSt.empty() || val <= minSt.top())
            minSt.push(val);
    }
    
    void pop() {
        if(st.top() == minSt.top())
            minSt.pop();

        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
