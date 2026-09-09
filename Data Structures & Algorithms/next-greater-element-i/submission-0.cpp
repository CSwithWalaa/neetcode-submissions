class Solution {
public:
// Monotonic decreasing stack
// O(n + m) time / O(n) space

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> st;
        unordered_map<int, int> nextGreater;

        // Process nums2 from right to left
        for(int i = nums2.size() - 1; i >= 0; i--) {            // O(n)

            int x = nums2[i];

            // Remove elements that cannot be the next greater
            while(!st.empty() && st.top() <= x) {
                st.pop();
            }

            // The top is the next greater element
            // THEN current element becomes a candidate
            nextGreater[x] = st.empty() ? -1 : st.top();
            st.push(x);
        }

        vector<int> res;

        for(int x : nums1) {                // O(m)
            res.push_back(nextGreater[x]);
        }

        return res;
    }
};