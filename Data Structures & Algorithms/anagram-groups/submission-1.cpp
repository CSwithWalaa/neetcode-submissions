class Solution {
public:
    // Time: O(m · n)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> res;

        for(const auto& s: strs) {         // m the number of strings
            // Frequency array with 26 counters for each lowecase English letter -> (0-25 positions)
            vector<int> count(26, 0);
            for(char c : s) {              // n the length of the string (longest one)
                count[c - 'a']++;
            }

            // Convert array into a string so you can use it as a key
            string key = to_string(count[0]);
            for(int i = 1; i < 26; ++i) {           // O(26) = O(1) 26 is a fixed constant
                key += ',' + to_string(count[i]);
            }
            // res[key] -> creates a new element and gives value to it and then
            // when an identical key shows, the element already exist so it adds that string within the same element
            res[key].push_back(s);
        }

        // Finally we get a hashmap, each element has key(string-converted count array) 
        // and an array list with string that are anagrams 
        // and then we add these lists into a list of sublists  

        vector<vector<string>> result;
        for(const auto& pair : res) {  
            result.push_back(pair.second);
        } 
        return result;
    }
};

/*  [ string s -> const string& s -> const auto& s ]
    for(const auto& s : strs) MEANS give me a reference to each string, 
    don't copy it, and don't let me modify it. 
*/

/*  each element inside the map is a key-value pair.
    for(const auto& pair : res) MEANS give me a refrence to each key-value pair, 
    don't copy it, and don't let me modify it. 
*/
