class Solution {
public:

    // Approach 1 (optimal): Frequency Array Count
    // Time Complexity: O(n) where N is the length of the string
    // Space Complexity: O(1) because the array size is fixed at 26

    bool isAnagram(string s, string t) {

        if(s.length() != t.length()) 
            return false;

        int count[26] = {0};

        for(char c : s) {               // O(n)
            count[c - 'a']++;
        }

        for(char c : t) {               // O(n)
            count[c - 'a']--;
        }

        for(int i = 0; i < 26; i++) {   // O(1) - Constant time since loop always runs exactly 26 times
            if(count[i] != 0) 
                return false;
        }

        return true;
    }
};

// Approach 2 (Alternative): Sorting Method 
/*
    // Time O(n log n) _ Space O(1) / O(n) depending on the language's sort implementation
    
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()) 
            return false;
            
        sort(s.begin(), s.end());            // O(n log n)
        sort(t.begin(), t.end());            // O(n log n)

        return s == t;
    }
*/

// Approach 3: Unicode Support (Scalable for Emojis / International Text)
/*
    // Time O(n) _ Space O(u) where u is the number of unique characters in the string

    bool isAnagram(string s, string t) {

        if(s.length() != t.length()) 
            return false;

        unordered_map<char, int> countMap;

        for(char c : s) {                           // O(n)
            countMap[c]++;
        }

        for(char c : t) {                           // O(n)
            countMap[c]--;
        }

        for(auto const& [key, value] : countMap) {  // O(u) - Loops through unique keys
            if(value != 0)
                return false;
        }
        
        return true;
    }
*/
