#include <bits/stdc++.h>
using namespace std;

int move(int a, int b){
    int c= a;
    while(a % b != 0){
        a++;
    }
    return(a-c);
}

int main(){

    int t;
    cin>>t;
    
    while(t--){
        int a, b;
        cin>>a>>b;

        int moveCount= move(a, b);
        cout<<moveCount<<endl;
    }



    return 0;
}