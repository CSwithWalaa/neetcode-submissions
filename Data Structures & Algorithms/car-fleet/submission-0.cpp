class Solution {
public:
// O(n log n) time / O(n) space

    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = position.size();
        vector<pair<int, double>> cars;

        // store position and arrival time
        for(int i  = 0; i < n; i++) {

            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // closest to target first
        sort(cars.begin(), cars.end(),
             [](auto& a, auto& b) {
                return a.first > b.first;
             });

        stack<double> st;

        for(auto& car: cars) {
            double time = car.second;

            // If this car arrives later than the fleet ahead,
            // it cannot catch that fleet -> start a new one
            while(st.empty() || time > st.top()) {
                st.push(time);
            }

            // otherwise it joins the fleet ahead (same one we're on)
        }

        return st.size();
    }
};
