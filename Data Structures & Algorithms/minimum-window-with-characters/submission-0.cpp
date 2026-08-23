class Solution {
public:
// O(n + m) time / O(k) space / k number of unique characters in s and t

    string minWindow(string s, string t) {
        unordered_map<char, int> sFreq;
        unordered_map<char, int> tFreq;

        for(char c : t) {                            // O(m)
            tFreq[c]++;
        }

        int need = tFreq.size();
        int have = 0;

        int l = 0;
        int index1 = 0;
        int minLen = INT_MAX;

        for(int r = 0; r < s.length(); r++) {            // O(2n) = O(n) time 

            // Invalid -> expand -> update window (have)
            if(tFreq.contains(s[r])) {
                sFreq[s[r]]++;

                if(sFreq[s[r]] == tFreq[s[r]]) {
                    have++;
                }
            }

            // When valid -> shrink -> record smallest window
            while(have == need) {
                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    index1 = l;
                }

                if(tFreq.contains(s[l])) {
                    sFreq[s[l]]--;

                    if(sFreq[s[l]] < tFreq[s[l]]) {
                        have--;
                    }
                }
                l++;     
            }
        }
        if(minLen == INT_MAX) 
            return "";

        return s.substr(index1, minLen);
    }
};
