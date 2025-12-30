class Solution {
public:
    bool valid(vector<vector<int>>& v) {
        // Check the sum of rows, columns, and diagonals
        if (v[0][0] + v[0][1] + v[0][2] == 15 &&
            v[1][0] + v[1][1] + v[1][2] == 15 &&
            v[2][0] + v[2][1] + v[2][2] == 15 &&
            v[0][0] + v[1][0] + v[2][0] == 15 &&
            v[0][1] + v[1][1] + v[2][1] == 15 &&
            v[0][2] + v[1][2] + v[2][2] == 15 &&
            v[0][0] + v[1][1] + v[2][2] == 15 &&
            v[0][2] + v[1][1] + v[2][0] == 15) {
                
            // Check if it contains all numbers from 1 to 9
            vector<int> a;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    a.push_back(v[i][j]);
                }
            }
            sort(a.begin(), a.end());
            for (int i = 0; i < 9; i++) {
                if (a[i] != i + 1) return false;
            }
            return true;
        }
        return false;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        if (rows < 3 || cols < 3) return 0; // Grid is too small for any 3x3 magic square
        
        vector<vector<int>> v(3, vector<int>(3));  // Preallocate a single 3x3 matrix
        
        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {
                // Fill the 3x3 matrix
                for (int m = 0; m < 3; m++) {
                    for (int n = 0; n < 3; n++) {
                        v[m][n] = grid[i + m][j + n];
                    }
                }
                if (valid(v)) ans++;
            }
        }
        return ans;
    }
};
