#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N, K;
        cin>>N>>K;

        int maxAnd= 0;
        for(int i= 1; i<=N; i++){
            for(int j= i+1; j<= N; j++ ){
                int anD= i & j;
                if(anD < K && anD >maxAnd) maxAnd= anD;
            }
        }
        cout<<maxAnd<<endl;
    }
    return 0;
}