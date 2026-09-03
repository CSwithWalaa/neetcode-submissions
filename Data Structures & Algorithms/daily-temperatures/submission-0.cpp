class Solution {
public:
// O(n) time / O(n) space
// stack stores indices NOT values

    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();

        vector<int> result(n, 0);

        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevDay = st.top();
                st.pop();

                result[prevDay] = i - prevDay;
            }
            st.push(i);
        }
        return result;
    }
};
