class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int n=nums.size();
        for(auto &it:mp){
           int x=it.second[0];
           int y=it.second.back();
            it.second.insert(it.second.begin(),y-n);
            it.second.push_back(x+n);
        }

        int q=queries.size();

        for(int i=0;i<q;i++){
              int x=nums[queries[i]];
            if(mp[x].size()==3){
                queries[i]=-1;
                continue;
            }
           int posidx=lower_bound(mp[x].begin(),mp[x].end(),queries[i])-mp[x].begin();           
         queries[i]=min(mp[x][posidx+1]-mp[x][posidx],queries[i]-mp[x][posidx-1]);
                    }

        return queries;
    }
};