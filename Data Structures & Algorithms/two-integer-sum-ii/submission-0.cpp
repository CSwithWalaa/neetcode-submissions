class Solution {
public:
    // Time O(n) - Space O(1)
    // non-decreasing sorted array, 1-indexed
    // if it wasn't sorted, hashmap approach would've been the optimal solution 

    vector<int> twoSum(vector<int>& numbers, int target) {
        int L = 0;
        int R = numbers.size() - 1;
        
        while(L < R) {
            int cursum = numbers[L] + numbers[R];

            if(cursum > target) {
                R--;
            }
            else if(cursum < target) {
                L++;
            }
            else {
                return {L + 1, R + 1};
            }
        }
        return {};
    }
};
