#include <bits/stdc++.h>
using namespace std;

int maximizingXor(int x, int y){
    int maxXor= 0;
    for(int i= x; i <= y; i++){
        for(int j= x+ 1; j <=y; j++){
            int xoR= i^j;
            if(xoR > maxXor) maxXor= xoR;
        }
    }
    return maxXor;
}
int main(){
    int l, r;
    cin>>l >>r;
    cout<<maximizingXor(l, r)<<endl;

    return 0;
}