class Solution {
public:
   bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            if (arr[current] == 0) {
                return true;
            }

            int next1 = current + arr[current];
            int next2 = current - arr[current];

            if (next1 < n && !visited[next1]) {
                visited[next1] = true;
                q.push(next1);
            }

            if (next2 >= 0 && !visited[next2]) {
                visited[next2] = true;
                q.push(next2);
            }
        }

        return false;
    }
};