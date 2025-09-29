// Modular exponentiation function
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Corrected countGoodNumbers function
int countGoodNumbers(long long n) {
    const int MOD = 1e9 + 7;
    long long odd = mod_pow(5, (n + 1) / 2, MOD);
    long long even = mod_pow(4, n / 2, MOD);
    return (odd * even) % MOD;
}
