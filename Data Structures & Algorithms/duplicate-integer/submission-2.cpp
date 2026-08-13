class Solution {
public:
    // Approach 1 (Optimal): Hash Set
    // Time O(n) _ Space O(n)  
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for(int num : nums) {               // O(n)
            if(seen.contains(num)) {        // O(1) - hash set lookups
                return true;
            }
            seen.insert(num);
        }

        return false;
    }
};

// Approach 2 (Alternative): Sorting
// Time O(n log n) _ Space: O(1) auxiliary space (typical in-place analysis)
/*
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());                     // O(n log n)

        for(int i = 0; i < nums.size() - 1; i++) {          // O(n)
            if(nums[i] == nums[i + 1]) {
                return true;
            }
        }

        return false;
    }
*/

// Approach 3 (Brute Force)
// Time O(n2) _ Space O(1) 
/* 
    bool hasDuplicate(vector<int>& nums) {

        for(int i = 0; i < nums.size() - 1; i++)                // O(n2)
        {   
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] == nums[j]) {
                    return true;
                }
            }  
        }

        return false;
    }
*/