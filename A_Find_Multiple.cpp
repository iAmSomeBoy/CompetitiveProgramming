#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C;
    cin>>A>>B>>C;
    bool flag= true; //nai dhorlam
    
    for(int i= A; i<= B; i++){
        if(i%C == 0){
            flag = false;
            cout<<i<<endl;
            break;
        }
    }
    if(flag){
        cout<<-1<<endl;
    }

    return 0;
}