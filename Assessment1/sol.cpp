
class Solution {
  public:
    long long gcd(long long x, long long y) { return y == 0 ? x : gcd(y, x % y); }

    int nthMagicalNumber(int n, int a, int b) {
        const int MOD = 1e9 + 7;

        long long lcm = (1LL * a * b) / gcd(a, b);

        long long low = 1;
        long long high = 1LL * n * min(a, b);

        while (low < high) {
            long long mid = low + (high - low) / 2;

            long long count = mid / a + mid / b - mid / lcm;

            if (count < n)
                low = mid + 1;
            else
                high = mid;
        }

        return low % MOD;
    }
};
