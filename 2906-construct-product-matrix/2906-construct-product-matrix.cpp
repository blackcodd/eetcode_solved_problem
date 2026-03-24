class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int MOD = 12345;

        int size = n * m;
        vector<int> arr(size);

        // flatten grid
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                arr[i*m + j] = grid[i][j];
            }
        }

        vector<int> prefix(size, 1), suffix(size, 1);

        // prefix
        for(int i = 1; i < size; i++){
            prefix[i] = ((prefix[i-1]%MOD) * (arr[i-1]%MOD)) % MOD;
        }

        // suffix
        for(int i = size - 2; i >= 0; i--){
            suffix[i] = ((suffix[i+1] %MOD) * (arr[i+1] % MOD))%MOD;
        }

        // result
        for(int i = 0; i < size; i++){
            arr[i] = ((prefix[i]%MOD )* (suffix[i]%MOD)) % MOD;
        }

        // put back into grid
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                grid[i][j] = arr[i*m + j];
            }
        }

        return grid;
    }
};
