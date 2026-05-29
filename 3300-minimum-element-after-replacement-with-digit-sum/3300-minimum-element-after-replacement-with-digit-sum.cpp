class Solution {
private:
 int numtosum( int a){
    int ans=0;
    while(a){
        ans+=a%10;
        a/=10;
    }
    return ans;
 }
public:
    int minElement(vector<int>& nums) {
        int minelement=INT_MAX;
        for(auto it:nums){
            minelement=min(minelement,numtosum(it));
        }
        return minelement;
        
    }
};