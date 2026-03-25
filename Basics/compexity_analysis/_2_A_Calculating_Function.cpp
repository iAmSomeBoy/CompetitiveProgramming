//f(n) =  - 1 + 2 - 3 + .. + ( - 1)^n *n
#include <bits/stdc++.h>
using namespace std;

long long f(long long n){
    if(n % 2==0) return n/2;   //n even
    else return(-(n+1)/2);     //n odd
}

int main(){

    long long n;
    cin>>n;

    cout<<f(n)<<endl;

    return 0;
}