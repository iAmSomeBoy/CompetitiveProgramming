#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long sum= n* (n+1)/2;
        long long sum2pow= 1;
        for(long long i= 2; i<=n; i=i*2){
                      
            sum2pow= sum2pow+ i;
        }
        cout<<sum-2*sum2pow<<endl;
    }
    return 0;
}