class Solution {
public:
    int T[7][7];                  // transition table
    unordered_set<long long> seen;

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        memset(T, 0, sizeof(T));

        // build transition table
        for (auto &a : allowed) {
            int x = a[0] - 'A';
            int y = a[1] - 'A';
            int z = a[2] - 'A';
            T[x][y] |= (1 << z);
        }

        int n = bottom.size();
        vector<vector<int>> A(n, vector<int>(n, 0));

        // bottom row store
        for (int i = 0; i < n; i++) {
            A[n - 1][i] = bottom[i] - 'A';
        }

        return solve(A, 0LL, n - 1, 0);
    }

    bool solve(vector<vector<int>>& A, long long R, int N, int i) {

        // ✅ top reached successfully
        if (N == 1 && i == 1) {
            return true;
        }

        // 🔸 parent row fully constructed
        else if (i == N) {

            // already tried this row → no need to try again
            if (seen.count(R)) return false;

            // cache this row
            seen.insert(R);

            // move one level up
            return solve(A, 0LL, N - 1, 0);
        }

        // 🔹 try placing parent blocks
        else {
            int w = T[A[N][i]][A[N][i + 1]];

            // try all possible parents
            for (int b = 0; b < 7; b++) {
                if ((w >> b) & 1) {

                    // place parent
                    A[N - 1][i] = b;

                    // encode row state and recurse
                    if (solve(A, R * 8 + (b + 1), N, i + 1))
                        return true;
                }
            }
            return false;
        }
    }
};
