class Solution {
public:
// L = 0 (buy day) / R = 1 (sell day) 
// price[R] > price[L] --> update maxProfit
// price[R] < price[L] --> L = R, expand R (R++) [as L is a cheaper buying price]

    // Time O(n) - Space O(1)
    int maxProfit(vector<int>& prices) {
        int L = 0, R = 1;
        int maxP = 0;
        
        while(R < prices.size()) {
            if(prices[R] > prices[L]) {
                int profit = prices[R] - prices[L];
                maxP = max(maxP, profit);
            } else {
                L = R;
            }
            R++;
        }
        return maxP;
    }
};
