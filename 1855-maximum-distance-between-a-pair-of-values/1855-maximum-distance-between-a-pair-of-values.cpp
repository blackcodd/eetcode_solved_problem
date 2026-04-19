class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        reverse(nums2.begin(),nums2.end());
        int sz2=nums2.size();
        int sz1=nums1.size();
        int ans=0;
        for(int i=0;i<sz1;i++){
            int idx=lower_bound(nums2.begin(),nums2.end(),nums1[i])-nums2.begin();
            int real_idx=sz2-1-idx;
            if(idx==sz2) continue;
            if(real_idx>=i)  ans=max(ans,real_idx-i);
        }
        return ans;
    }
};