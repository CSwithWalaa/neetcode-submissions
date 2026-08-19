class Solution {
public:
// start moving by our r pointer untill the end of our string
// when we see a character that already exist in our string -> we start shrinking  
// our window from the left to right untill there're no repeated characters
// So we always have a valid substring + we track its maximum size

// O(n) time / O(m) space
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int l = 0;
        int res = 0;

        for (int r = 0; r < s.size(); r++) 
        {                                       // n - length of the string
            while (charSet.contains(s[r])) 
            {                                   // m - number of unique chars in the string
                charSet.erase(s[l]);
                l++;
            }
            charSet.insert(s[r]);
            res = max(res, r - l + 1);
        }
        return res;
    }
};
