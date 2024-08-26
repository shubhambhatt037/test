#include<iostream>
using namespace std;
void saydigit(string str[],int n)
{
    //base case
    if(n==0)
        return ;

    //processing
    int digit=n%10;
    n=n/10;

    //recursive call
    saydigit(str,n);
    cout<<str[digit]<<endl; 
    cout<<endl;
}

int main()
{
    string arr[10]={"zero","one","two",
                    "three","four","five",
                    "six","seven","eight","nine"};
    int n;
    cout<<"\nEnter value of n-> ";
    cin>>n;
    cout<<endl;
    saydigit(arr,n);
    cout<<endl;
    return 0;
}