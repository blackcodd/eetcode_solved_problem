class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int i=0;
        int j=n-1;
        int ans=0;
       for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
            if(colors[j]!=colors[i]){
                ans=max(ans,j-i);
                break;
            }
        }
       }
       return ans;
        
    }
};