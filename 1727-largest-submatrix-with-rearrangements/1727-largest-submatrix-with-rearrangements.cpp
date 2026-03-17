

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> One_of_each_column (m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[j][i]==1){
                    if(j==0) One_of_each_column[j][i]=1;
                    else One_of_each_column[j][i]=One_of_each_column[j-1][i]+1;
                }
            }
        }
        int max_area=0;
        for(int i=0;i<m ;i++){
            int min_hight=INT_MAX;
            int cnt=0;
            vector<int>temp=One_of_each_column[i];
            sort(temp.begin(),temp.end(),greater<int>());
            for(int j=0;j<n;j++){
                min_hight=min(min_hight,temp[j]);
                cnt++;
                max_area=max(max_area,min_hight*cnt); 
            }
            
           
        }
        return max_area;
        
    }
};