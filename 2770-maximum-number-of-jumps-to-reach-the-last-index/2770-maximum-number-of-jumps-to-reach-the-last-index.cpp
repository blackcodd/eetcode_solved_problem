class Solution {
private:

    int solve(vector<int>& nums, int ind, int target, vector<int>& dp) {

        if(ind == 0)
            return 0;

        if(dp[ind] != -2)
            return dp[ind];

        int ans = -1;

        for(int i = ind - 1; i >= 0; i--) {

            if(abs(nums[ind] - nums[i]) <= target) {

                int temp = solve(nums, i, target, dp);

                if(temp != -1)
                    ans = max(ans, temp + 1);
            }
        }

        return dp[ind] = ans;
    }

public:

    int maximumJumps(vector<int>& nums, int target) {

        int n = nums.size();

        vector<int> dp(n, -2);

        return solve(nums, n - 1, target, dp);
    }
};