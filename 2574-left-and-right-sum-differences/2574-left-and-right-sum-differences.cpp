class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int a[1001]={0};
        a[0]=0;
        int total=0;
        for(int i=0;i<n;i++){
            if(i==0) a[i]=nums[i];
            else
            a[i]=a[i-1]+nums[i];

            total+=nums[i];
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int left=i>0 ? a[i-1]: 0 ;
            int right=total-a[i];
            ans[i]=abs(left-right);
        }
        return ans;
    }
};