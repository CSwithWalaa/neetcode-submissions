class Solution {
public:
// O(n) time / O(m) space 
// n - length of the string / m - total number of unique characters in the string
// optimal
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int maxf = 0;
        int l = 0, res = 0;

        for(int r = 0; r < s.size(); r++) {
            count[s[r]]++;
            maxf = max(maxf, count[s[r]]);

            while((r - l + 1) - maxf > k) {
                count[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
