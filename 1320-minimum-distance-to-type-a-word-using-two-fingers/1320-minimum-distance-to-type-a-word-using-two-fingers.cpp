#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dp[301][27][27]; 

  
    int dist(int a, int b){
        if(a == -1) return 0; 
        return abs(a/6 - b/6) + abs(a%6 - b%6);
    }

    int f(string &word, int indx, int f1, int f2){
        if(indx == word.size()) return 0;

        int &res = dp[indx][f1+1][f2+1];
        if(res != -1) return res;

        int cur = word[indx] - 'A';

    
        int use1 = dist(f1, cur) + f(word, indx+1, cur, f2);

       
        int use2 = dist(f2, cur) + f(word, indx+1, f1, cur);

        return res = min(use1, use2);
    }

public:
    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return f(word, 0, -1, -1);
    }
};