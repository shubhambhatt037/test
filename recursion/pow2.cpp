#include<iostream>
using namespace std;
int pow(int n)
{
    //base case
    if(n==0)
        return 1;

    //recursive relation    
    else
        return 2*pow(n-1);    
}
int main()
{
    int n;
    cout<<"Enter the power-> "<<endl;
    cin>>n;
    cout<<"Answer is -> "<<pow(n)<<endl;
    return 0;
}