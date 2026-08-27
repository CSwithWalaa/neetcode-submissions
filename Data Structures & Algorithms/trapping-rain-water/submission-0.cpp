class Solution {
public:
// O(n) time / O(n) space

// how high the water can rise at a position -> the tallest wall (to left and to right)
// the water can rise as high as the shorter of these two (leftMax/rightMax)
// water level = min(leftMax[i], rightMax[i]) - height[i]

// instead of finding max hight to left and max hight to right for every i
// leftMax[i], rightMax[i] -> prefix/suffix

    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) 
            return 0;

        vector<int> leftMax(n);
        vector<int> rightMax(n);

        leftMax[0] = height[0];
        for(int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        rightMax[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int water = 0;
        for(int i = 0; i < n; i++) {
            water += min(leftMax[i], rightMax[i]) - height[i];
        }
        return water;
    }
};
