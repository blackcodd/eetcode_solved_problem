class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();

        // dp[day][transactions_left][state]
        vector<vector<vector<long long>>> dp(
            n, vector<vector<long long>>(k + 1, vector<long long>(3, LLONG_MIN))
        );

        // Day 0 initialization
        for (int j = 0; j <= k; j++) {
            dp[0][j][0] = 0;               // no transaction
            if (j > 0) {
                dp[0][j][1] = -prices[0]; // buy first
                dp[0][j][2] =  prices[0]; // sell first
            }
        }

        // Fill DP
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                int p = prices[i];

                // state 0: no transaction running
                dp[i][j][0] = dp[i - 1][j][0];
                if (j > 0) {
                    dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][1] + p); // sell
                    dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][2] - p); // buy
                }

                // state 1: bought, waiting to sell
                dp[i][j][1] = dp[i - 1][j][1];
                if (j > 0) {
                    dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][0] - p);
                }

                // state 2: sold, waiting to buy
                dp[i][j][2] = dp[i - 1][j][2];
                if (j > 0) {
                    dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j - 1][0] + p);
                }
            }
        }

        return dp[n - 1][k][0];
    }
};
