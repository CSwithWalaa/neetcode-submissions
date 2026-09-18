class TimeMap {
// We're looking for the rightmost valid value

// n number of values of a key / m number of keys
// O(n * m) space

private:
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {}
    
    // O(1) time
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    // O(log n) time 
    string get(string key, int timestamp) {
        
        if(store.find(key) == store.end())
            return "";

        vector<pair<int, string>>& values = store[key];

        int left = 0;
        int right = values.size() - 1;

        string answer = "";

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(values[mid].first <= timestamp) {

                // Valid timestamp
                // But maybe there is a later valid one
                answer = values[mid].second;
                left = mid + 1;
            } 
            else {
                // Timestamp is too large
                right = mid - 1;
            }
        }

        return answer;
    }
};
