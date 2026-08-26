class Solution {
public:
// O(n) time / O(1) space
    int maxArea(vector<int>& heights) {
        // start with the widest possible pair

        int l = 0;
        int r = heights.size() - 1;
        int maxArea = 0;

        while(l < r) {
            // calc area and maintain the maximum one
            // NOTE: the water can only rise as high as the shortest line

            int width = r - l;
            int height = min(heights[l], heights[r]);

            int area = width * height;
            maxArea = max(maxArea, area);

            // width decreases no matter which pointer moves, so move the shortest line (height)
            // the shorter line is what's limiting the container's height
            if(heights[l] < heights[r]) 
                l++;
            else 
                r--;
        }
        return maxArea;
    }
};
