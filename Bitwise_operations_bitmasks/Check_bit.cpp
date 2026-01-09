/*
$ bit set means i understand is 1 ; it can be check by logical & operation
$ for reaching ith digit we use shift operator <<.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, i;
    cin>>N>>i;
    if(N & (1<<i))cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return 0;
}