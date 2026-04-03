#include <bits/stdc++.h>
using namespace std;

void evenIndx(string A,int Size){
    if(Size== 0) return ;
    cout<<A[Size];
    Size -=2;
    evenIndx(A, Size);
}


int main(){

    int N;
    string A;
    cin>>N;
    cin>>A;
    int Size= A.size();
    evenIndx(A, Size);

    
    return 0;
}