#include <bits/stdc++.h>
using namespace std;

int sum(int A[], int N){
    if(N<= 0) return 0;

    return( A[N-1] + sum(A, N-1));    

}

int main(){

    int T;
    cin>>T;
    while(T--){
        int i;
        static int  j=1;
        int N;
        cin>>N;
        int A[N];
        for(int i=0; i<N; i++){
            cin>>A[i];
        }
        cout<<"Case "<<j<<": "<<sum(A, N)<<endl;
        j++;
    }

    return 0;
}