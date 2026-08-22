class Solution {
public:
// O(26 * n) --> O(n) time / O(1) space
// as alphabets are 26 characters

// Maintain two frequency arrays.
// For every window: compare count1 and count2

    bool checkInclusion(string s1, string s2) {
        
        if(s1.length() > s2.length()) 
            return false;
        
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);

        // Frequency of s1
        for(char c : s1) {
            count1[c - 'a']++;
        }
        
        int l = 0;
        for(int r = 0; r < s2.length(); r++) {
            // Add right character
            count2[s2[r] - 'a']++;

            // Keep window size equal to s1.length()   
            if(r - l + 1 > s1.length()) {
                count2[s2[l] - 'a']--;
                l++;
            }

            // Check if frequencies match
            if(count1 == count2)
                return true;
        }
        return false;
    }
};
