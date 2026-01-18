
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        vector<vector<int>> rowSum(grid.size()+1, vector<int>(grid[0].size() + 1, 0));
        vector<vector<int>> colSum(grid.size() + 1, vector<int>(grid[0].size() + 1, 0));
        vector<vector<int>> diagSum1(grid.size() + 1, vector<int>(grid[0].size() + 1, 0));
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rowSum[i+1][j+1]=rowSum[i+1][j]+grid[i][j];
                colSum[i+1][j+1]=colSum[i][j+1]+grid[i][j];
                diagSum1[i+1][j+1]=diagSum1[i][j]+grid[i][j];
            }   
        }
        for(int size=min(n,m);size>=1;size--){
            for(int i=0;i+size-1<n;i++){
                for(int j=0;j+size-1<m;j++){
                    int targetSum=rowSum[i+1][j+size]-rowSum[i+1][j];
                    bool isMagic=true;
                    for(int k=0;k<size;k++){
                        if(rowSum[i+k+1][j+size]-rowSum[i+k+1][j]!=targetSum){
                            isMagic=false;
                            break;
                        }
                        if(colSum[i+size][j+k+1]-colSum[i][j+k+1]!=targetSum){
                            isMagic=false;
                            break;
                        }
                    }
                    if(!isMagic) continue;
                    int diagSum=0;
                    for(int k=0;k<size;k++){
                        diagSum+=grid[i+k][j+k];
                    }
                    if(diagSum!=targetSum) continue;
                    diagSum=0;
                    for(int k=0;k<size;k++){
                        diagSum+=grid[i+k][j+size-1-k];
                    }
                    if(diagSum!=targetSum) continue;
                    return size;
                }
            }
        }
        return 1;
        
    }
};