class Solution {
public:
// O(n) average time/ O(n) space

// HashSet (O(1) lookup - no duplicates) + Sequence Start (when num - 1 doesn't exist)
// We start a sequence only for numbers that have no predecessor NOT for every number
// while loop only happens for sequence beginnings

    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        int maxLen = 0;

        for(int num : nums) {
            if(numsSet.find(num - 1) == numsSet.end()) {
                // beginning of a sequence
                int length = 1;

                while(numsSet.find(num + 1) != numsSet.end()) {
                    num++;
                    length++;
                }
                maxLen = max(maxLen, length);
            }
        }
        return maxLen;
    }
};
