#include<stdio.h>

int function(int a)
{
    int sum = 0,digit ;
    while(a!=0)
        {
            digit = a % 10 ;
            sum = sum + digit ;
            a = a / 10 ;
        }
        return(sum);
}
int main()
{
    int t , a ;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&a);
        
        printf("%d\n",function(a));
    }
    return(0);
}