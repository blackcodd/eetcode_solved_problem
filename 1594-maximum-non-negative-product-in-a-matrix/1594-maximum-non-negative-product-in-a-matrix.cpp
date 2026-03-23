class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<long long>> maxDP(m, vector<long long>(n));
        vector<vector<long long>> minDP(m, vector<long long>(n));
        
        maxDP[0][0] = minDP[0][0] = grid[0][0];
        
        // first column
        for(int i = 1; i < m; i++){
            maxDP[i][0] = minDP[i][0] = maxDP[i-1][0] * grid[i][0];
        }
        
        // first row
        for(int j = 1; j < n; j++){
            maxDP[0][j] = minDP[0][j] = maxDP[0][j-1] * grid[0][j];
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                long long a = maxDP[i-1][j] * grid[i][j];
                long long b = minDP[i-1][j] * grid[i][j];
                long long c = maxDP[i][j-1] * grid[i][j];
                long long d = minDP[i][j-1] * grid[i][j];
                
                maxDP[i][j] = max({a,b,c,d});
                minDP[i][j] = min({a,b,c,d});
            }
        }
        
        long long res = maxDP[m-1][n-1];
        if(res < 0) return -1;
        
        return res % 1000000007;
    }
};