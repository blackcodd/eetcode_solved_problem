class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {

        // sort by (minimum required - actual cost)
        sort(tasks.begin(), tasks.end(),
            [](vector<int>& a, vector<int>& b) {
                return (a[1] - a[0]) > (b[1] - b[0]);
            });

        int requiredEnergy = 0;  // final answer
        int buffer = 0;          // extra leftover energy

        for (auto &task : tasks) {

            int minReq = task[1];
            int cost   = task[0];

            // if buffer is not enough, increase initial energy
            if (buffer < minReq) {
                requiredEnergy += (minReq - buffer);
                buffer = minReq;
            }

            // after doing task, buffer decreases by cost
            buffer -= cost;
        }

        return requiredEnergy;
    }
};