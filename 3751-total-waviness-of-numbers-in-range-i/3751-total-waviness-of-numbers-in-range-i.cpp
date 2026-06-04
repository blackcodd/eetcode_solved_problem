class Solution {
private:
 int totalwive(int n){
    string s=to_string(n);
    if(s.size()<3) return 0;
    int i=1;
    int cnt=0;
    while(i+1<s.size()){
        if(s[i]-'0' < s[i+1]-'0' && s[i]-'0' <s[i-1]-'0'){
            ++cnt;
        }
        if(s[i]-'0' > s[i+1]-'0' && s[i]-'0' >s[i-1]-'0'){
            ++cnt;
        }
        i++;
    }
    return cnt;
 }
public:
    int totalWaviness(int num1, int num2) {

     int ans=0;
     for(int i=num1;i<=num2;i++){
        ans+=totalwive(i);
     }
     return ans;
        
    }
};