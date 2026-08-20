class Solution {
public:
// O(m.n) time / O(m) space 
// n - length of the string / m - total number of unique characters in the string
    int characterReplacement(string s, int k) {
        unordered_set<char> charSet(s.begin(), s.end());
        int res = 0;

        for(char c : charSet) {
            int l = 0, count = 0;

            for(int r = 0; r < s.size(); r++) {
                if(s[r] == c)
                    count++;

                while((r - l + 1) - count > k) {
                    if(s[l] == c) { 
                        count--;
                    }
                    l++;
                }
           
                res = max(res, r - l + 1);
            }
        }
        return res;
    }
};
