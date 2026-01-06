#include <bits/stdc++.h>
using namespace std;

int main(){

    int A, B, C;
    cin>>A>>B>>C;

    int D= A*A + B*B;
    int E= C*C;
    cout << ((D < E) ? "Yes" : "No") << endl;

    return 0;
}