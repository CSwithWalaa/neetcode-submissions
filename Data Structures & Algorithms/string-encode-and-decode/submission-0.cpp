class Solution {
public:
// O(m + n) time/space

    // length + delimiter (#) + string
    string encode(vector<string>& strs) {           // O(n) / n - number of strings in the list
        string res;

        for(string& str : strs) {
            res += to_string(str.length());
            res += '#';
            res += str;
        }
        return res;
    }

    vector<string> decode(string s) {               // O(m) / m - sum of lengths of all strings
        vector<string> res;

        int i = 0;
        while(i < s.length()) {
            int j = s.find('#', i);                 // find the delimiter
            int len = stoi(s.substr(i ,j - i));     // read the length

            string str = s.substr(j + 1, len);      // take that many characters (len chars)
            res.push_back(str);                     // push it to your string list
            i = j + 1 + len;                        // jump to the next length
        }
        return res;
    }
};
