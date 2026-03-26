#include <bits/stdc++.h>
using namespace std;

void printNumber(int N){
    if(N==0) return ;
    else{
        cout<<N;
        if((N-1) != 0) cout<<" ";
        printNumber(N-1);
    }
}
int main(){
    int N;
    cin>>N;
    printNumber(N);
    return 0;
}
