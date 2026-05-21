class Solution {
public:
 int  common_prefix(int a, int b){
    string s1=to_string(a);
    string s2=to_string(b);
    int i=0;
    int cnt=0;
    while(i<min(s1.size(), s2.size())){
        if(s1[i]==s2[i]) ++cnt;
        else return cnt;
        i++;
    }
    return cnt;
 }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n1=arr1.size();
        int n2=arr2.size();
        unordered_set<string>s;
        for(int i=0;i<n1;i++){
            string as=to_string(arr1[i]);
             for(int j=1;j<=as.size();j++){
                s.insert(as.substr(0,j));
             }
        }
           int ans=0;
        for(int i=0;i<n2;i++){
            string as=to_string(arr2[i]);
         
            for(int j=1;j<=as.size();j++){
                if(s.find(as.substr(0,j))!=s.end()){
                    ans=max(ans,j);
                }
            }
        }
        return ans;
    }
};