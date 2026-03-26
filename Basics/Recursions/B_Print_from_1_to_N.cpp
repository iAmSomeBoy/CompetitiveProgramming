#include <bits/stdc++.h>
using namespace std;

void printNumber(int N, int i){
    if(i> N) return ;
    else{
        cout<<i<<endl;
        printNumber(N, ++i);
    }
}

int main(){
    int N;
    cin >> N;
    printNumber(N, 1);
    return 0;
}
