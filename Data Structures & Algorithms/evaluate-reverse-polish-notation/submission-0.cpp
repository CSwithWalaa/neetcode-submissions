class Solution {
public:
// O(n) time / O(n) space
// n - number of tokens

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(const string& token: tokens) {

            // Number -> push
            if(token != "+" && token != "-" &&
               token != "*" && token != "/") {

                st.push(stoi(token));
            }

            // Operator
            else {
                int right = st.top();
                st.pop();

                int left = st.top();
                st.pop();

                if(token == "+") {
                    st.push(left + right);
                } 
                else if(token == "-")  { 
                    st.push(left - right);
                }
                else if(token == "*") { 
                    st.push(left * right);
                }
                else if(token == "/") {
                    st.push(left / right);
                }
            }
        }
        return st.top();
    }
};
