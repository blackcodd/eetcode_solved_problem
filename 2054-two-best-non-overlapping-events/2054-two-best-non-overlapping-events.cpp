class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        // sort by start time
        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });

        // suffix max values
        vector<int> suf(n);
        suf[n-1] = events[n-1][2];

        for(int i = n-2; i >= 0; i--) {
            suf[i] = max(suf[i+1], events[i][2]);
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            int cur = events[i][2];

            // binary search next event with start > end
            int l = i+1, r = n-1, idx = -1;
            while(l <= r) {
                int mid = (l+r)/2;
                if(events[mid][0] > events[i][1]) {
                    idx = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            if(idx != -1) {
                cur += suf[idx];
            }

            ans = max(ans, cur);
        }

        return ans;
    }
};
