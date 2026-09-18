class Solution {
public:
// O(log n) time / O(1) space
// We need to find target in O(log n) time -> Binary Search -> Sorted array
// BUT at least one half of the current search range is always sorted

    int search(vector<int>& nums, int target) {
        
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            // Did I find the target?
            if(nums[mid] == target) 
                return mid;

            // Which half is sorted?
            // Is the target inside that sorted half?
            if(nums[left] <= nums[mid]) {
                if(target >= nums[left] && target <= nums[mid])
                    right = mid - 1;
                else 
                    left = mid + 1;
            } 
            else {
                if(target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        // If not found
        return -1;
    }
};
