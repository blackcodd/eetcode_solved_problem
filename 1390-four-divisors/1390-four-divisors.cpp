class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; 1LL * i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;

        for (int n : nums) {

            // Case 1: n = p^3
            int p = round(cbrt(n));
            if (1LL * p * p * p == n && isPrime(p)) {
                totalSum += 1 + p + p*p + p*p*p;
                continue;
            }

            // Case 2: n = p * q
            for (int i = 2; 1LL * i * i <= n; i++) {
                if (n % i == 0) {
                    int p = i;
                    int q = n / i;
                    if (p != q && isPrime(p) && isPrime(q)) {
                        totalSum += (1 + p) * (1 + q);
                    }
                    break;  // Only first factor needed
                }
            }
        }
        return totalSum;
    }
};
