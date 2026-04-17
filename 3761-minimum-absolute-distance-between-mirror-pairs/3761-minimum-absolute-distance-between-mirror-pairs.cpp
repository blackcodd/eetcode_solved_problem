class Solution {
private:
int Reverse_Int(int n){
    string s=to_string(n);
    reverse(s.begin(),s.end());
    int i=0;
    while(s[0]=='0'){
        s.erase(s.begin());
    }
    return stoi(s);
}

public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        for(int i=0;i<n;i++){
           int rev=Reverse_Int(nums[i]);
            if(mp.find(rev)!=mp.end()){
               int point_right= upper_bound(mp[rev].begin(),mp[rev].end(),i)-mp[rev].begin();
                if(point_right!=mp[rev].size()){
                    ans=min(ans,mp[rev][point_right]-i);
                }

            }
        }
        return ans==INT_MAX?-1:ans;
        
    }
};