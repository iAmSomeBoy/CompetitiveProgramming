#include <bits/stdc++.h>
using namespace std;

int main(){

    int y;
    cin>>y;
    
    
    while(true){
        y= y+1;
        string s= to_string(y);
        int a= s[0];
        int b= s[1];
        int c= s[2];
        int d= s[3];
        if(a!= b && a!= c && a!=d && b!= a && b!= c && b!= d && c!= a && c!= b && c!= d && d!= a && d!= b&& d!= c){
            cout<<y<<endl;
            return 0;
        }
    }

    return 0;
}