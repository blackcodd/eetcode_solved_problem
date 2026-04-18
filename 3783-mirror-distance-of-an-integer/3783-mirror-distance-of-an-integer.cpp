class Solution {
private:
int Rev(int n){
    int x=n;
    int cnt=0;
    while(x){
         x/=10;
         ++cnt;
    }
    int y=0;
    while(n){
        y+=(n%10)*pow(10,cnt-1);
        cnt--;
        n/=10;
    }
    return y;
}

public:
    int mirrorDistance(int n) {
         return abs(n-Rev(n));
    }
};