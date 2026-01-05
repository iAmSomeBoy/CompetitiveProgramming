#include<bits/stdc++.h>
using namespace std;

void func(int* a, int* b){
    int temp = abs((*a) - (*b));
    *a = *a + *b;
    cout<<(*a)<<endl;
    cout<<temp<<endl;
}
int main(){
    int a, b;
    cin>>a>>b;

    func(&a, &b);

    return 0;
}
