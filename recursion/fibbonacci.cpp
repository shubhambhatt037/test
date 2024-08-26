#include<iostream>
using namespace std;
int fibb(int n)
{
    //base case
    if(n==0)
        return 0;
    if(n==1)
        return 1;

    int ans= fibb(n-1)+fibb(n-2);    
    return ans;
}

int main()
{
    int n;
    cout<<"Enter value of n "<<endl;
    cin>>n;
    cout<<"Answer is-> "<<fibb(n)<<endl;
    return 0;
}