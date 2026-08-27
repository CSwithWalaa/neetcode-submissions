class Solution {
public:
// O(n) time / O(1) space

    int trap(vector<int>& height) {
        if(height.empty())
            return 0;
            
        // maintain leftMax and rightMax without storing arrays & two pointers
        int l = 0; 
        int r = height.size() - 1;

        int leftMax = 0;
        int rightMax = 0;
        int water = 0;

        // The water level is determined by min(leftMax, rightMax).
        // If height[l] < height[r], the left side is the limiting side,
        // so we can safely calculate water using leftMax.
        // Otherwise, process the right side using rightMax.
        while(l < r) {
            if(height[l] < height[r]) {
                if(height[l] <= leftMax) {
                    water += leftMax - height[l];
                } else {
                    leftMax = height[l];
                }
                l++;
            } else {
                if(height[r] <= rightMax) {
                    water += rightMax - height[r];
                } else {
                    rightMax = height[r];
                }
                r--;
            }
        }
        return water;
    }
};
