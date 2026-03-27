class Solution {
public:
    void left_shift(vector<int>& v) {
        int sz = v.size();
        int f = v[0];
        for (int i = 1; i < sz; i++) {
            v[i - 1] = v[i];
        }
        v[sz - 1] = f;
    };
    void right_shift(vector<int>& v) {
        int sz = v.size();
        int l = v[sz - 1];
        for (int i = sz - 2; i >= 0; i--) {
            v[i + 1] = v[i];
        }
        v[0] = l;
    };

public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> prev = mat;
        int m = mat.size();
        int n = mat[0].size();
        int shift = k % n;
        if (shift == 0)
            return true;
    

            for (int i = 0; i < m; i++) {
                 for(int j=0;j<n;j++){
                if (i % 2 == 0) {
                   mat[i][j]=mat[i][(j+shift)%n];
                } else {
                   mat[i][j]=mat[i][(j-shift+n)%n];
                }

                 if(mat[i][j]!=prev[i][j]) return false;
              }
             
        }

    return true;
        
    }

}
;