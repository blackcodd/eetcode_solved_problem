class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

      unordered_map<int,int>m1,m2;
      int n=A.size();
      vector<int>C(n);
      int prev=0;
      for(int i=0;i<n;i++){
        m1[A[i]]++;
        m2[B[i]]++;
        int curr=0;
        if(m2.count(A[i])) curr++;
        if(m1.count(B[i])) curr++;
        if(A[i]==B[i]) curr--;

        prev+=curr;
        C[i]=prev;

      }
      return C;

    }
};