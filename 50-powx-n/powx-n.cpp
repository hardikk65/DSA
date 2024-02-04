class Solution {
public:
    double myPow(double x, long long n) {
        n = static_cast<long long>(n);
        if (n == 0) return 1;
        if (n < 0) return myPow(1 / x, abs(n));
        
        if (n % 2 != 0) {
            return x * myPow(x, n - 1);
        } else {
            double temp = myPow(x, n / 2);
            return temp * temp;
        }
    }
};
