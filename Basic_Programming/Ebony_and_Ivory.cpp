#include <bits/stdc++.h>
using namespace std;

int main(){

    int a, b, c;
    cin>>a>>b>>c;
    bool flag = true; //dhorenilam parbena
    for(int i= 0; i<=c; i=i+a){
        if((c- i)% b==0){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    for(int j= 0; j<=c; j= j+b){
        if((c-j)%a==0){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;

    return 0;
}