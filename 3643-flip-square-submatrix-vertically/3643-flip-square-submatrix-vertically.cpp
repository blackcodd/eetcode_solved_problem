class Solution {
public:
void f(vector<vector<int>>& v, int x, int y, int k) {
   
    for (int i = 0; i < k / 2; i++) {
        for (int j = 0; j < k; j++) {
            swap(v[x + i][y + j], v[x + k - 1 - i][y + j]);
        }
    }

}
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
          f(grid,x,y,k);return grid; 
    }
};