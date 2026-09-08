class MinStack {
// One Stack storing pairs
// O(1) time for all operations / O(n) space 

private:
    stack<pair<int, int>> st;

public:
    MinStack() {}
    
    void push(int val) {
        if(st.empty()) {
            st.push({val, val});
        } 
        else {
            int currentMin = min(st.top().second, val);
            st.push({val, currentMin});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
