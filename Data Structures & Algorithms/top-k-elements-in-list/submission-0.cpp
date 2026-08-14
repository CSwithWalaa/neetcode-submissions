class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Sorting - time O(n log n) 
        
        // 1. count frequencies (create hashmap -> count -> copy key-value pairs to array of pairs)
        // 2. sort
        // 3. take the last k elements (the highest)

        unordered_map<int, int> freq;

        for(int num : nums) {
            freq[num]++;
        }

        vector<pair<int, int>> arr;
        for(const auto& p : freq) {
            arr.push_back({p.second, p.first});
            // p.second -> freq -> first| p.first -> number -> second | so we sort them according to freq
        }

        sort(arr.rbegin(), arr.rend());     // high to low

        vector<int> topK;
        for(int i = 0; i < k; i++) {
            topK.push_back(arr[i].second);
        }

        return topK;
    }
    
};
