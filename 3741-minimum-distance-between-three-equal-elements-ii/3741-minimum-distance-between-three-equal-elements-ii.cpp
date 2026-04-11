class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,deque<int>> mp;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
            if(mp[nums[i]].size()>2){
              ans=min(ans,mp[nums[i]].back()-mp[nums[i]].front());
              mp[nums[i]].pop_front();
            }
            
        }
        return ans==INT_MAX?-1:2*ans;

        
    }
};
