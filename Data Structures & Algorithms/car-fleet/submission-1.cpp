class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = position.size();
        vector<pair<int, int>> cars;

        // store position and speed
        for(int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        // sort the vector cars in descending order (largest to smallest)
        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double prevTime = 0;

        // CALC arrival time and count fleets at the same time
        for(auto [pos, spd] : cars) {
            double time = (double)(target - pos) / spd;

            if(time > prevTime) {
                fleets++;
                prevTime = time;
            }
        }

        return fleets;
    }
};
