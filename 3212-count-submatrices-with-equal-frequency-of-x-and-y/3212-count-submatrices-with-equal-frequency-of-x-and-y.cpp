class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, 0)));
        int cnt=0;

        if(grid[0][0]=='X')
            dp[0][0][0]=1;
        else if (grid[0][0]=='Y')
            dp[0][0][1]=1;
          

        for(int i=1;i<m;i++){
            if(grid[i][0]=='.'){
               dp[i][0][0]=  dp[i-1][0][0];
                dp[i][0][1]=dp[i-1][0][1];
            }
            else{
                dp[i][0][0]=dp[i-1][0][0]+(grid[i][0]=='X');
                dp[i][0][1]=dp[i-1][0][1]+(grid[i][0]=='Y');
            }  

            if(dp[i][0][0]>0 && dp[i][0][1]>0 && dp[i][0][0]==dp[i][0][1]){
                cnt++;
            }
                
        }

        for(int j=1;j<n;j++){
            if(grid[0][j]=='.'){
                dp[0][j][0]=  dp[0][j-1][0];
                dp[0][j][1]=dp[0][j-1][1];
            }
            else{
                dp[0][j][0]=dp[0][j-1][0]+(grid[0][j]=='X');
                dp[0][j][1]=dp[0][j-1][1]+(grid[0][j]=='Y');
            }   
            if(dp[0][j][0]>0 && dp[0][j][1]>0 && dp[0][j][0]==dp[0][j][1]){
                cnt++;
            }   
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j]=='X'){
                    dp[i][j][0]=dp[i-1][j][0]+dp[i][j-1][0]-dp[i-1][j-1][0]+1;
                    dp[i][j][1]=dp[i-1][j][1]+dp[i][j-1][1]-dp[i-1][j-1][1];
                }
                else if(grid[i][j]=='Y'){
                    dp[i][j][0]=dp[i-1][j][0]+dp[i][j-1][0]-dp[i-1][j-1][0];
                    dp[i][j][1]=dp[i-1][j][1]+dp[i][j-1][1]-dp[i-1][j-1][1]+1;
                }
                else{
                    dp[i][j][0]=dp[i-1][j][0]+dp[i][j-1][0]-dp[i-1][j-1][0];
                    dp[i][j][1]=dp[i-1][j][1]+dp[i][j-1][1]-dp[i-1][j-1][1];
                }
                    if(dp[i][j][0]>0 && dp[i][j][1]>0 && dp[i][j][0]==dp[i][j][1]){
                        cnt++;
                    }
            }
        }

        // int ans=0;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j][0]<< "," <<dp[i][j][1]<<" _-> ";
        //         if(dp[i][j][0]>0 && dp[i][j][1]>0 && dp[i][j][0]==dp[i][j][1]){
        //             ans++;
        //         }
        //     }
        //     cout<<endl;
        // }

        return cnt;
    }
};