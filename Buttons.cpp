#include <bits/stdc++.h>
using namespace std;

int main(){

    int A, B;
    cin>>A>>B;

    int C= A + B;
    int D= max(A, B);
    int E= D + (D-1);
    int ans= max(C, E);
    cout<<ans<<endl;
    return 0;
}