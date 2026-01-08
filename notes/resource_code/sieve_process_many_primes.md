```
const int N = 1000000;
vector<bool> isPrime(N+1, true);
vector<int> primes;

void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= N; j += i)
                isPrime[j] = false;
        }
    }
}
```