#include <bits/stdc++.h>
using namespace std;

void recurSion(int N){
    if (N==0) return;
    else{
        cout<<"I love Recursion"<<endl;
        recurSion(N-1);  // Call recursively with N-1
    }
}
int main(){
    int N;
    cin>>N;
    recurSion(N);

    return 0;
}