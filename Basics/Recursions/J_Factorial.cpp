#include <bits/stdc++.h>
using namespace std;
long long printFactorial(long long N){
    if(N== 0 || N== 1) return 1;
    else{
        return(N* printFactorial(N-1));
    }

}
int main(){

    long N;
    cin>>N;

    cout<<printFactorial(N)<<endl;;



    return 0;
}