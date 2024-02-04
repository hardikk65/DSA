class Solution {
public:
    int myPow(long long x, long long n,int mod) {
        if(n==0) return 1;
        
        if(n%2 == 0){
            long long temp = myPow(x, n/2,mod);
            temp = temp%mod; 
            return (temp*temp)%mod;
        }
        
        return (x*myPow(x, n - 1,mod))%mod;
    }
    int countGoodNumbers(long long n) {
        long long mod = pow(10,9) + 7;
        if(n%2==0){
            return ((myPow(4,n/2,mod)%mod)*(myPow(5,n/2,mod)%mod))%mod;
        }
        
        return ((myPow(4,n/2,mod)%mod)*(myPow(5,(n/2) + 1,mod)%mod))%mod;
        

        

        
    }
};