class Solution {
public:
    vector<int> plusOne(vector<int>&a) {
        int n=a.size();
        for(int j=n-1;j>=0;j--){
            if(a[j]<9){
                a[j]+=1;
                return a;
            }
            else{
                a[j]=0;
            }
        }
        if(a[0]==0) {
            vector<int>ans;
            ans.push_back(1);
            for(auto it:a){
                ans.push_back(it);
            }
            return ans;
        }
        else return a;
    }
};