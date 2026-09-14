class Solution {
public:
// O(n) time / O(n) space 

    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;
        int maxArea = 0;

        // we need i when it's = heights.size()
        // at the end of the histogram -> there are no more bars -> so pretend the next 
        // bar has height 0 and force everyone still waiting in the stack to finish

        for(int i = 0; i <= heights.size(); i++) {

            int currHeight = 
                    (i == heights.size() ? 0 : heights[i]);

            while(!st.empty() && currHeight < heights[st.top()]) {

                int h = heights[st.top()];
                st.pop();

                int left = (st.empty() ? -1 : st.top());
                int width = i - left - 1;

                int area = width * h;
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }
        return maxArea;
    }
};
