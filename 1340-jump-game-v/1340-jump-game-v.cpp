#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int function(vector<int>& arr, int d, int i, vector<int>& dp) {
        if (dp[i] != -1) return dp[i];
        int ans = 1;
        for (int j = i + 1; j <= min((int)arr.size() - 1, i + d); j++) {
            if (arr[j] < arr[i]) {
                ans = max(ans, 1 + function(arr, d, j, dp));
            } else {
                break;
            }
        }
        for (int j = i - 1; j >= max(0, i - d); j--) {
            if (arr[j] < arr[i]) {
                ans = max(ans, 1 + function(arr, d, j, dp));
            } else {
                break;
            }
        }
        return dp[i] = ans;
    }


public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        int ans = 1;
        for (int i = 0; i < n; i++) {
            ans = max(ans, function(arr, d, i, dp));
        }
        return ans;
    
    
    }
};