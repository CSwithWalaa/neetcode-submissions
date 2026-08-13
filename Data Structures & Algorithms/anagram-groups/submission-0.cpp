class Solution {
public:
    // Sorting O(m.n log n)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
 
        unordered_map<string, vector<string>> res;
        for(const auto& s : strs) {                    // O(m.n log n) - m is number of strings 
            string sortedS = s;                        // O(n) - copying the string (suppose n its length)
            sort(sortedS.begin(), sortedS.end());      // O(n log n)
            res[sortedS].push_back(s);
        }

        vector<vector<string>> result;
        for(auto& pair : res) {
            result.push_back(pair.second);
        }
        return result;
    }
};
