class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(nums[i]!=n-1 && mp.count(nums[i]) || nums[i]>n-1 ) return false;
            mp[nums[i]]++;
        }
        cout<<n<<" "<<mp.size()<<endl;
        return mp[n-1]==2 && mp.size()==n-1;
        
    }
};