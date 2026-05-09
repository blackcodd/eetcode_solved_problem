class Solution {
public:
vector<int> insert( int layer , vector<vector<int>>& grid){
    vector<int>ans;
    int m=grid.size(), n=grid[0].size();
    for(int i=layer; i<n-layer-1; i++) ans.push_back(grid[layer][i]);
    for(int i=layer; i<m-layer-1; i++) ans.push_back(grid[i][n-layer-1]);
    for(int i=n-layer-1; i>layer; i--) ans.push_back(grid[m-layer-1][i]);
    for(int i=m-layer-1; i>layer; i--) ans.push_back(grid[i][layer]);
    return ans;
}

public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size(), m=grid[0].size();
        int layers=min(n,m)/2;
      vector<vector<int>>ans(layers, vector<int>());
      for(int i=0; i<layers; i++) ans[i]=insert(i, grid);
        for(int i=0; i<layers; i++){
            int size=ans[i].size();
            vector<int>temp(size);
            for(int j=0; j<size; j++) temp[j]=ans[i][(j+k)%size];
            ans[i]=temp;
        }
        vector<vector<int>>res(n, vector<int>(m));
        for(int i=0; i<layers; i++){
            int idx=0;
            for(int j=i; j<m-i-1; j++) res[i][j]=ans[i][idx++];
            for(int j=i; j<n-i-1; j++) res[j][m-i-1]=ans[i][idx++];
            for(int j=m-i-1; j>i; j--) res[n-i-1][j]=ans[i][idx++];
            for(int j=n-i-1; j>i; j--) res[j][i]=ans[i][idx++];
        }
        return res;
    }
};