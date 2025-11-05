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
vector<int> sieve(int n) { 
    vector<int> spf(n + 1);
    for (int i = 1; i <= n; ++i) {
        spf[i] = i;
    }
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

vector<int> facPrime(int n, vector<int>& spf) {
    vector<int> fac;
    while (n > 1) {
        int p = spf[n];
        fac.push_back(p);
        while (n % p == 0)
            n /= p;
    }
    return fac;
}
vi numDivs(int n) {
    vi divs;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            divs.pb(i);
            if(i != n / i) divs.pb(n / i);
        }
    }
    sort(all(divs));
    return divs;
}