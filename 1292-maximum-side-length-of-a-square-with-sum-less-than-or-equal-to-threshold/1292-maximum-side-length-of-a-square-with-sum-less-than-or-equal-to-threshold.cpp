class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                prefixSum[i][j] = mat[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
            }
        }
        
        int left = 0, right = min(m, n), result = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            bool found = false;
            
            for (int i = mid; i <= m; ++i) {
                for (int j = mid; j <= n; ++j) {
                    int total = prefixSum[i][j] - prefixSum[i - mid][j] - prefixSum[i][j - mid] + prefixSum[i - mid][j - mid];
                    if (total <= threshold) {
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
            
            if (found) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
        
    }
};