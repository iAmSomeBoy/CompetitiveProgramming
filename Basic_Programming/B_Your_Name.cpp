#include <bits/stdc++.h>
using namespace std;

int main(){

    int q;
    cin>>q;
    while(q){
        q--;
        int n;
        cin>>n;
        string s, t;
        cin>>s;
        cin>>t;

        s= s.substr(0, n);
        t= t.substr(0, n);
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if(s ==t ){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }


    return 0;
}