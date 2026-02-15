class Solution {
public:
    string addBinary(string a, string b) {
         int i=a.size()-1;
         int j=b.size()-1;
         int carry=0;
          string ans="";
          int fi,se;
         while(i>-1 || j>-1){
             if(i>=0){
                 fi=a[i]-'0';
               i--;
             }
             else{
                 fi=0;
             }
             if(j>=0){
                 se=b[j]-'0';
                 j--;
             }
             else {
                 se=0;
             }
                  cout<<fi<<" "<<se<<endl;
              int sum=fi+se+carry;
              
              cout<<sum<<endl;

              if(sum==0){
                carry=0;
                ans+="0";
              }
              if(sum==1){
                carry=0;
                ans+="1";
              }
              if(sum==2){
                carry=1;
                ans+="0";
              }
              if(sum==3){
                carry=1;
                ans+="1";
              }

         };
         reverse(ans.begin(),ans.end());
         if(carry==1){
            ans="1"+ans;
         }
        return ans;

        
    }
};