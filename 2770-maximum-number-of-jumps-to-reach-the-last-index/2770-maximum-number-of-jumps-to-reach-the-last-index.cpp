class Solution {
private:
 int  maxValue(vector<int>& nums ,int ind , int target ,vector<int>&dp){
        if(ind==0) return  dp[0]=0;
        if(dp[ind]!=-2) return dp[ind];
        int ans=-1;
        for(int i=ind-1;i>=0;i--){
            if(abs(nums[ind]-nums[i])<=target){
                int temp=maxValue(nums,i,target,dp);
                if(temp!=-1)  ans=max(ans,temp+1);
            }
        }
        return dp[ind]=ans;
    }
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(nums.size()+1 , -2 );
        return maxValue(nums,n-1,target ,dp );

    }
};