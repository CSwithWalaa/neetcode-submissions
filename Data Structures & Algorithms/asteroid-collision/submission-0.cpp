class Solution {
public:
// O(n) amortized time / O(n) space

    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;

        for(int asteroid : asteroids) {

            bool destroyed = false;

            // Collision is possible only when:
            // top moves right and current moves left
            while(!st.empty() && st.top() > 0 && asteroid < 0) {

                int top = st.top();

                // when asteroid is destroyed THEN continue the while loop
                // to check with previous ones
                if(abs(top) < abs(asteroid)) {
                    st.pop();
                    continue;
                } 

                // when asteroid is destroyed THEN you go to the next one 
                // by breaking th while loop 
                if(abs(top) == abs(asteroid)) {
                    st.pop();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                } 
            }

            // make sure asteroid is NOT destroyed before you push it
            if(!destroyed) {
                st.push(asteroid);
            }
        }

        vector<int> result(st.size());

        // convert stack to vector in original order
        for(int i  = result.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};