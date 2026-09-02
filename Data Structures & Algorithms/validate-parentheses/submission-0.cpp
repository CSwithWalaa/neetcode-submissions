class Solution {
public:
// O(n) time / O(n) space

// 1. When we encounter an opening bracket -> we need to remember it.
//    As we don't know which closing bracket will eventually close it.
// 2. When a closing bracket arrives, it must match the most recently opened bracket.

    bool isValid(string s) {
        stack<char> st;

        for(char c : s) {

            // Opening bracket
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 

            // Opening bracket
            else {
                if(st.empty())
                    return false;

                char top = st.top();

                if(c == ')' && top != '(') 
                    return false;

                if(c == '}' && top != '{') 
                    return false;

                if(c == ']' && top != '[') 
                    return false;

                st.pop();
            }
        }
        return st.empty();
    }
};
