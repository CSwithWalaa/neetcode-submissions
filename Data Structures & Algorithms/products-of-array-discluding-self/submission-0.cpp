class Solution {
public:
// O(n) time / O(1) extra space
// O(1) extra space -> instead of 2 arrays -> store the prefix products directly at res

// output[i] = product of evrything to the left * product of evrything to the right
// prefix[i] = product of evrything before i / suffix[i] = product of evrything after i

    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);

        int prefix = 1;
        for(int i = 0; i < nums.size(); i++) {
            res[i] *= prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            res[i] *= suffix;
            suffix *= nums[i];
        }
        return res;
    }
};
