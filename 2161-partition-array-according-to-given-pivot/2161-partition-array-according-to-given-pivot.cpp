
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // In-place stable partition: first move all < pivot to front,
        // then move all == pivot after them. Uses std::rotate to keep
        // relative order and works in-place (O(n^2) worst-case).
        auto stable_partition_range = [&](int l, int r, auto pred) {
            // partition [l, r) so that elements satisfying pred come first
            int write = l;
            for (int read = l; read < r; ++read) {
                if (pred(nums[read])) {
                    if (read != write) std::rotate(nums.begin() + write, nums.begin() + read, nums.begin() + read + 1);
                    ++write;
                }
            }
            return write; // first index after moved block
        };

        int n = nums.size();
        int mid = stable_partition_range(0, n, [&](int x){ return x < pivot; });
        stable_partition_range(mid, n, [&](int x){ return x == pivot; });
        return nums;
    }       
};