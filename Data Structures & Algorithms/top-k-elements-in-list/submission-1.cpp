class Solution {
public:
    // Frequency Map + Bucket Sort → time O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1. Count frequencies
        unordered_map<int, int> count;

        for(int num : nums) {
            count[num]++;
        }

        // 2. Create buckets
        vector<vector<int>> buckets(nums.size() + 1); 

        // 3. Put each number into its frequency buckets
        for(const auto& entry : count) {
            buckets[entry.second].push_back(entry.first);
        }

        // 4. Walk backwards through buckets
        vector<int> res;
        for(int i = buckets.size() - 1; i > 0; --i) {
           for(int n : buckets[i]) {
               res.push_back(n);
               if(res.size() == k) 
                  return res;
           }
        }
        return res;
    }
};
