class Solution {
public:
// Floyd's Cycle Detection
// O(n) time / O(1) space

    int findDuplicate(vector<int>& nums) {
        
        // Find intersection point
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        // Find cycle entrance
        slow = nums[0];

        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
