class Solution {
public:
// O(m + n) time/space
// Manual j scan
    string encode(vector<string>& strs) {
        string res;

        for(const string& str : strs) {
            res.append(to_string(str.length()));
            res.push_back('#');
            res.append(str);
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;

        int i = 0;
        while(i < s.length()) {
            int j = i;
            while(s[j] != '#') {           // my # index
                j++;
            }

            int len = stoi(s.substr(i, j - i));
            i = j + 1;                  // beginning of my string
            j = i + len;                // next encoded chunk
            res.push_back(s.substr(i, len));
            i = j;
        }
        return res;
    }
};
