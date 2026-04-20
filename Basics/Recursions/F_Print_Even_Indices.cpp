#include <bits/stdc++.h>
using namespace std;

void evenIndx(int A[], int Size){
    if(Size <= 0) return ;
    if(Size % 2==0){
        cout<<A[Size-2]<<" ";
        return evenIndx(A, Size-2);
    }
    if(Size % 2 != 0){
        cout<<A[Size-1]<<" ";
        return evenIndx(A, Size-2);
    }
    
}

int main(){

    int N;
    cin>>N;
    int A[N];
    for(int i= 0; i<N; i++){
        
        cin>>A[i];

    }
    evenIndx(A, N);

    return 0;
}