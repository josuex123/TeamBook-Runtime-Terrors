vector<bool> sieve(int n){
    vector<bool> primes(n + 1, true);
    primes[0] = primes[1] = false;

    for(int i = 2; i * i <= n; i++){
        if(primes[i])
            for(int j = i * i; j <=n; j+=i)
                primes[j] = false;
    }
    return primes;

}
vector<bool> sieve(int n) { 
    vector<bool> spf(n+1);
    for (int i = 1; i <= n; ++i) {  spf[i] = i;  }
    for (int i = 2; i * i <= n; ++i) {
        if (spf[i] == i) { 
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == j) { 
                    spf[j] = i;
                }
            }
        }
    }
    return spf;
}
vector<bool>facPrime(int n, vi& primes){
    vector<bool> fac;
    while(n > 1){
        int p = primes[n];
        fac.pb(p);
        while(n % p == 0) n /= p;
    }
    return fac;
}