class Solution {
public:
// O(n) time / O(n) space

    int calPoints(vector<string>& operations) {
        stack<int> st;

        for(const string& op : operations) {

            if(op == "C") {
                st.pop();
            }

            else if(op == "D") {
                int last = st.top();
                st.push(2 * last);
            }

            else if(op == "+") {
                int last = st.top();
                st.pop();

                int secLast = st.top();

                st.push(last);
                st.push(last + secLast);
            }

            // Numeric score
            else {
                st.push(stoi(op));
            }
        }
        
        // Calculate total
        int total = 0;

        while(!st.empty()) {
            total += st.top();
            st.pop();
        }

        return total;
    }
};