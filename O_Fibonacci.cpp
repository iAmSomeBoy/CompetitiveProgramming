#include <bits/stdc++.h>
using namespace std;

int printFibonacci(int N){
    if(N== 1) return 0;
    if(N== 2) return 1;
    else{
        return(printFibonacci(N-2)+ printFibonacci(N-1));
    }


    
}

int main(){
    int N;
    cin>> N;

    cout<<printFibonacci(N)<<endl;

    return 0;
}