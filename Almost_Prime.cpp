#include <bits/stdc++.h>
using namespace std;

vector<int> primes;

void sieve(int n){
    vector<bool> isPrime(n+1, true);
    for(int i= 2; i<= n; i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(int j= i*2; j<= n; j= j+ i){
                isPrime[j]= false;
            }
        }
    }
}


int main(){
    int n;
    cin>>n;
    sieve(n);
    for(int i: primes){
        cout<<i<<" ";
    }
    

    return 0;
}