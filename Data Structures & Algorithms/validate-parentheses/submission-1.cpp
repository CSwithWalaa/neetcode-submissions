class Solution {
public:
// Open  _ push
// Close _ check top + pop
// End   _ stack mist be empty

    bool isValid(string s) {
        stack<char> st;

        for(char c : s) {

            // push
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            }

            // check top + pop
            // either it's false and done OR things go well so you pop
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
