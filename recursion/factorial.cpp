#include<iostream>
using namespace std;
int fact(int n)
{
    //base case
    if(n<=1)
        return 1;
    else
        return n*fact(n-1);
}
int main()
{
    int n;
    cout<<"Enter number to find factorial=> "<<endl;
    cin>>n;
    cout<<"Factorial of "<<n<<" is -> "<<fact(n)<<endl;
    return 0;
}