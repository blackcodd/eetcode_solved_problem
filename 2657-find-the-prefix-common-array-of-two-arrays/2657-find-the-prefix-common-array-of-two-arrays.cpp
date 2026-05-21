class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

      
      int n=A.size();
      vector<int>m1(n+1,0),m2(n+1,0);
      vector<int>C(n);
      int prev=0;
      for(int i=0;i<n;i++){
        m1[A[i]]++;
        m2[B[i]]++;
        int curr=0;
        if(m2[A[i]]==1) curr++;
        if(m1[B[i]]==1) curr++;
        if(A[i]==B[i]) curr--;

        prev+=curr;
        C[i]=prev;

      }
      return C;

    }
};