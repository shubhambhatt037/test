#include<iostream>
using namespace std;

int exponent(int n,int p)
{
    //base case
    if(p==0)
        return 1;

    if(p==1)
        return n;    

    //Recursive call    
    int ans=exponent(n,p/2);
    if(p%2==0)
        return ans*ans;
    else
        return n*ans*ans;
}
int main()
{
    int n,p;
    cout<<"Enter number and power respectively-> "<<endl;
    cin>>n>>p;
    cout<<"Answer is-> "<<exponent(n,p)<<endl;
    return 0;
}