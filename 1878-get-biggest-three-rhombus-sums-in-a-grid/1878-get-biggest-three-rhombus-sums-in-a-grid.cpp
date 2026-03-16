#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
private:
    int calculate_the_sum(int i,int j,int k,vector<vector<int>>& grid){
    int m=grid.size(), n=grid[0].size();
    
    if(i-k<0 || i+k>=m || j+2*k>=n) return -1;

    int sum = 0;

    int x=i, y=j;

    // left -> top
    for(int t=0;t<k;t++){
        sum += grid[x-t][y+t];
    }

    // top -> right
    for(int t=0;t<k;t++){
        sum += grid[x-k+t][y+k+t];
    }

    // right -> bottom
    for(int t=0;t<k;t++){
        sum += grid[x+t][y+2*k-t];
    }

    // bottom -> left
    for(int t=0;t<k;t++){
        sum += grid[x+k-t][y+k-t];
    }

    return sum;
}
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        if(m*n <3) {
           vector<int>aa;
           for(auto it:grid){
             for(auto it1:it){
                aa.push_back(it1);
             }
           }
           return aa;
        }
        set<int,greater<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 if(ans.find(grid[i][j])==ans.end()){
                   ans.insert(grid[i][j]);
                 } 
                int k=1;
                while(true){
                    int sum=calculate_the_sum(i,j,k,grid);
                    if(sum==-1) break;
                    else {
                      if(ans.find(sum)==ans.end()){
                     ans.insert(sum);
                 } 
                    }
                    k++;

                }
            }
        }
        int cnt=0;
        vector<int>ans_vector;
        for(auto it:ans){
              ans_vector.push_back(it);
              cnt++;
              if(cnt==3) break;
        }
        return  ans_vector;
    }

};