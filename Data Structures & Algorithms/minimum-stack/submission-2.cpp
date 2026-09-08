class MinStack {
// Two Stacks
// O(1) time for all operations / O(n) space 

private:
    stack<int> st;
    stack<int> minSt;

public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);

        if(minSt.empty()) 
            minSt.push(val);
        else
            minSt.push(min(minSt.top(), val));   
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
