class Solution {
    static const long long MOD = 1e9 + 7;
    private:
    long long power(long long base, long long exp) {
    if (exp == 0) 
        return 1;

    long long half = power(base, exp / 2);
    half = (half * half) % MOD;

    if (exp & 1)
        return (half * base) % MOD;
    else
        return half;
}

public:
    int countGoodNumbers(long long n) {
       long long even= (n+1)/2;
       long long odd=n/2;

       return (power(5,even) * power(4,odd)) % MOD;
    }
};