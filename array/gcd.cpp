#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    if(a==0)
        return b;
    else if(b==0)
        return a;

    while(a!=b)
    {
        if(a>b)
            a=a-b;
        else if(b>a)
            b=b-a;    
    }    
    return a;
}
int main()
{
    int ans,a,b;
    cout<<"\nEnter value of A-> ";cin>>a;
    cout<<"\nEnter value of B-> ";cin>>b;

    ans = gcd(a,b);

    cout<<"GCD of A and B is-> "<<ans<<endl;
    return 0;
}