
class Solution {
private:
bool DFS( int sr,int sc,vector<vector<int>>&grid){
    if(sr==grid.size()-1)return true;
    grid[sr][sc]=1;
    vector<int>dir={0,1,0,-1,0};
    for(int i=0;i<4;i++){
        int r=sr+dir[i];
        int c=sc+dir[i+1];
        if(r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c]==0){
            if(DFS(r,c,grid))return true;
        }
    }
    return false;

}
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n=cells.size();
        int m=cells[0].size();
        int left=0;
        int right=n-1;
        int ans=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            vector<vector<int>>grid(row,vector<int>(col,0));
            for(int i=0;i<=mid;i++){
                int r=cells[i][0]-1;
                int c=cells[i][1]-1;
                grid[r][c]=1;
            }
            bool flag=false;
            for(int i=0;i<col;i++){
                if(grid[0][i]==0 && DFS(0,i,grid)){
                    flag=true;
                    break;
                }
            }
            if(flag){
                ans=mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return ans+1;
    }
};