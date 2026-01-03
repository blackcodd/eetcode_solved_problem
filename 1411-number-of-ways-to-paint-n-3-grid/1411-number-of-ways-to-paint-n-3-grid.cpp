#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1e9 + 7;

    int numOfWays(int n) {
        vector<vector<int>> states;

        // Step 1: Generate all valid row states
        for (int a = 1; a <= 3; a++) {
            for (int b = 1; b <= 3; b++) {
                for (int c = 1; c <= 3; c++) {
                    if (a != b && b != c) {
                        states.push_back({a, b, c});
                    }
                }
            }
        }

        int m = states.size(); // should be 12

        // Step 2: Precompute compatibility
        vector<vector<int>> compat(m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                bool ok = true;
                for (int k = 0; k < 3; k++) {
                    if (states[i][k] == states[j][k]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) compat[i].push_back(j);
            }
        }

        // Step 3: DP
        vector<long long> dp(m, 1), newdp(m);

        for (int row = 1; row < n; row++) {
            fill(newdp.begin(), newdp.end(), 0);
            for (int i = 0; i < m; i++) {
                for (int j : compat[i]) {
                    newdp[j] = (newdp[j] + dp[i]) % MOD;
                }
            }
            dp = newdp;
        }

        // Step 4: Sum answer
        long long ans = 0;
        for (long long x : dp) ans = (ans + x) % MOD;
        return ans;
    }
};
