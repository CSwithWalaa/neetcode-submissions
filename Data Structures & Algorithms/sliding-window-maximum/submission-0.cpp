class Solution {
public:
// O(n) time / O(n) space
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n - k + 1);
        deque<int> q;
        int l = 0, r = 0; 

        while(r < n) {
            // remove indices from back while their values are < nums[r]
            // they can never be maximum again
            while(!q.empty() && nums[q.back()] < nums[r]) {
                q.pop_back();
            }

            // add r to back of deque
            q.push_back(r);

            // remove front if it's otside the window
            if(q.front() < l) {
                q.pop_front();
            }

            // once window reaches size k, add q.front (max of this window) to res
            // and move l -> start new iteration
            if(r + 1 >= k) {
                res[l] = nums[q.front()];
                l++;
            }
            r++;
        }
        return res;
    }
};
