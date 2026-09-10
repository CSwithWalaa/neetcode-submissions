class MyQueue {
// using two stacks [input - output]
// twice reversing gives us FIFO behavior

private:
    stack<int> inputSt;
    stack<int> outputSt;

    void transfer() {
        while(!inputSt.empty()) {

            outputSt.push(inputSt.top());
            inputSt.pop();
        }
    }

public:
    MyQueue() {}
    
    void push(int x) {
        inputSt.push(x);
    }
    
    int pop() {
        if(outputSt.empty())
            transfer();

        int x = outputSt.top();
        outputSt.pop();

        return x;
    }
    
    int peek() {
        if(outputSt.empty())
            transfer();

        return outputSt.top();
    }
    
    bool empty() {
        return inputSt.empty() && outputSt.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */