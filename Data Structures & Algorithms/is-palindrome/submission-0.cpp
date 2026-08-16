class Solution {
public:
    // Time O(n) - we scan through the string only one time. pointers go forward/inward. 
    // Space O(1) - we only have two integer pointers and few variables
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while(left < right) {

            while(left < right && !isalnum(s[left])) {
                left++;
            }

            while(left < right && !isalnum(s[right])) {
                right--;
            }

            if(tolower(s[left]) != tolower(s[right])) {
                return false;
            } 
            left++; right--;
        }
        return true;
    }
};
