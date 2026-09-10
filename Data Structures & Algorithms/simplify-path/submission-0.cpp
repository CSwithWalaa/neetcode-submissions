class Solution {
public:
    string simplifyPath(string path) {

        stack<string> st;

        string current;

        // Add one directory token to the stack
        auto process = [&]() {
            if (current.empty() || current == ".") {
                // Empty token or current directory -> ignore
            }
            else if (current == "..") {
                // Go to parent directory
                if (!st.empty()) {
                    st.pop();
                }
            }
            else {
                // Normal directory
                st.push(current);
            }

            current.clear();
        };

        for (char c : path) {

            if (c == '/') {
                process();
            }
            else {
                current += c;
            }
        }

        // Process the last token
        process();

        // Stack contains the canonical directories
        string result;

        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result.empty() ? "/" : result;
    }
};