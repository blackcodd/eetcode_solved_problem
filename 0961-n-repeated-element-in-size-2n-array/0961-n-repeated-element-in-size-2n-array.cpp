class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int mx_num=0;
        unordered_map<int,int>mp;int n=nums.size()/2;
        for(auto it:nums){
                 mp[it]++;
                 if( mp.count(it) && mp[it]==n) return it;
        }
        return -1;
        
    }
};