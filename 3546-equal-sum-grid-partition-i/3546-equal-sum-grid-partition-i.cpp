class Solution {
public:
long long  rowsum(vector<vector<int>>&v, int r){
 long long ans=0;
    for(int i=0;i<v[0].size();i++){
          ans+=v[r][i];
    }
    return ans;
 }
long long colsum(vector<vector<int>>&v, int col){
    long long  ans=0;
    for(int i=0;i<v.size();i++){
          ans+=v[i][col];
    }
    return ans;
 }
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum_mat=0;
        for(auto it:grid){
            for(auto init:it){
                sum_mat+=init;
            }
        }
        long long temp=0;
        for(int i=0;i<grid.size();i++){
            temp+=rowsum(grid,i);
            if(temp==(sum_mat-temp)) return true;
        }
        temp=0;
        for(int i=0;i<grid[0].size();i++){
            temp+=colsum(grid,i);
            if(temp==(sum_mat-temp)) return true;
        }
        return false;
    }
};