class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Approach 1 : Hash Map (Two Pass)
        // Time O(n) _ Space O(n)

        // [key _ info] -> [value _ index]
        unordered_map<int, int> indicies;

        int index = 0;
        for(int num : nums) {                       // O(n)
            indicies[num] = index++;
        }
        
        for(int i = 0; i < nums.size(); i++) {      // O(n)
            int diff = target - nums[i];
            if(indicies.contains(diff) && i != indicies[diff]) {    // O(1)
                if(i < indicies[diff]) {
                    return {i, indicies[diff]};
                } else {
                    return {indicies[diff], i};
                }
            }
        }

        return {};
    }
};

// Approach 2 (Alternative): Hash Map (One Pass) 
// Loops the array only once
/*
    // Time O(n) _ Space O(n)

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indicies;

        for(int i = 0; i < nums.size(); i++) {      // O(n)
            int diff = target - nums[i];

            if(indicies.contains(diff)) {    // O(1)
                return {indicies[diff], i};
            }

            indicies[nums[i]] = i;
        }

        return {};
    }
*/

// Approach 3 (Brute Force)
/*
    // Time O(n2) _ Space O(1)

    vector<int> twoSum(vector<int>& nums, int target) {

        for(int i = 0; i < nums.size(); i++) {              // O(n2)
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {};
    }
*/
