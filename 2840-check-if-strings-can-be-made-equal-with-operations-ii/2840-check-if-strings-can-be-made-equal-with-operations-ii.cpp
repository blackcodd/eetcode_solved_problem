class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int>evenhashs1(26,0);
        vector<int>oddhashs1(26,0);
          vector<int>evenhashs2(26,0);
        vector<int>oddhashs2(26,0);
        for(int i=0;i<s1.size();i++){
            if(i%2==0){
                evenhashs1[s1[i]-'a']++;
                evenhashs2[s2[i]-'a']++;
                }
            else{
                oddhashs1[s1[i]-'a']++;
                oddhashs2[s2[i]-'a']++;
            }
        }
        
        return (evenhashs1==evenhashs2) && (oddhashs1==oddhashs2);
    }
};