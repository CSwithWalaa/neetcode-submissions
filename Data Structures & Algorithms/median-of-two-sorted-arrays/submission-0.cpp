class Solution {
public:
// O(log m) time / O(1) space

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // Binary search the smaller array (smaller search space)
        if(nums1.size() > nums2.size()) 
            swap(nums1, nums2);

        int m = nums1.size();
        int n = nums2.size();

        int left = 0;
        int right = m;

        while(left <= right) {

            
            int partition1 = left + (right - left) / 2;

            // Number of elements needed from nums2
            // to make the left half contain half of all elements
            int partition2 = (m + n + 1) / 2 - partition1;

            int nums1Left = 
                (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];

            int nums1Right = 
                (partition1 == m) ? INT_MAX : nums1[partition1];

            int nums2Left = 
                (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];

            int nums2Right =
                (partition2 == n) ? INT_MAX : nums2[partition2];

            // Correct Partition
            if(nums1Left <= nums2Right && nums2Left <= nums1Right) {
                
                // Odd number of elements
                if((m + n) % 2 == 1) {
                    return max(nums1Left, nums2Left);
                }

                // Even number of elements
                return (max(nums1Left, nums2Left) + 
                        min(nums1Right, nums2Right)) / 2.0;
            } 
            // Too many elements taken from nums1
            else if(nums1Left > nums2Right) {
                right = partition1 - 1;
            } 
            // Not enough elements taken from nums1
            else {
                left = partition1 + 1;
            }
        }

        return 0.0;
    }
};
