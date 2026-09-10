class StockSpanner {
private:
    stack<pair<int, int>> st;

public:
    StockSpanner() {}
    
    // For each call: amortized time O(n) /  space O(1)
     
    int next(int price) {
        int span = 1;

        // Merge all previous prices <= today's price
        while(!st.empty() && st.top().first <= price) {

            span += st.top().second;
            st.pop();
        }

        // Store today's price and its total span
        st.push({price, span});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */