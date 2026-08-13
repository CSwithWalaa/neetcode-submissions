class Solution {
public:

    // Approach 1 (optimal): Frequency Array Count
    // Time O(n) _ Space O(1) as the array size is fixed at 26

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

        for(int i = 0; i < 26; i++) {   // O(1) - constant time since loop always runs exactly 26 times
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
