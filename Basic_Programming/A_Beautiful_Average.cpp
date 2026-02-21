#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> V(n);
        int x;

        for(int i=0; i< n; i++){
            cin>>x;
            V.push_back(x);
        }

        int maxValue= *max_element(V.begin(), V.end());
        cout<<maxValue<<endl;
       
    }

    return 0;
}