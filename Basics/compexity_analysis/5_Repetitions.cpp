#include <bits/stdc++.h>
using namespace std;

int main(){

    string chain;
    cin>>chain;

    int maxLength=1, currentLength= 1;
    for(int i= 1; i< chain.size(); i++){
        if(chain[i]== chain[i -1]) currentLength++;
        else{
            maxLength= max(maxLength, currentLength);
            currentLength= 1;
        }
    }
    cout<<maxLength<<endl;
    return 0;
}