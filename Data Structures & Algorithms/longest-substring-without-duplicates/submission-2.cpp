class Solution {
public:
// Instead of "Which characters are currently in my window?" -> hashset
// we remember: "Where did I last see this character?"       -> hashmap

// O(n) time / O(m) space
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int L = 0;
        int maxLen = 0;

        for(int R = 0; R < s.size(); R++) 
        {                                           // n - length of the string
            if(lastSeen.contains(s[R])) {           // m - number of unique chars in the string
                L = max(L, lastSeen[s[R]] + 1);
            }
            lastSeen[s[R]] = R;
            maxLen = max(maxLen, R - L + 1);
        }
        return maxLen;
    }
};
