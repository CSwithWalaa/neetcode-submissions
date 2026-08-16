class Solution {
public:
    // Time O(n2) - O(log n) + O(n * n) = O(n2)
    // Space O(log n) - std::sort requires O(log n) auxiliary stack space
    // meanwhile the output memory not counted as auxiliary space complexity
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
         
        for(int i = 0; i < nums.size(); i++) {
            // if we get the same value again we skip the iteration (so we don't get the same result again)  
            // "I already used this value as my first number. Don't start another search with the same value."  

            // Skip duplicate first values 
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            int L = i + 1, R = nums.size() - 1;
            while(L < R) {
                int threeSum = nums[i] + nums[L] + nums[R];

                if(threeSum > 0) {
                    R--;
                } else if(threeSum < 0) {
                    L++;
                }
                else {
                    result.push_back({nums[i], nums[L], nums[R]});
                    L++;
                    R--;

                    // Skip duplicate second values
                    while(L < R && nums[L] == nums[L - 1]) {
                        L++;
                    }
                    // Skip duplicate third values
                    while(L < R && nums[R] == nums[R + 1]) {
                        R--;
                    }
                }
            }
        }
        return result;
    }
};
