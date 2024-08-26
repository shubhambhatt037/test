#include<iostream>
using namespace std;

bool checkPalindrome(string str,int i,int j)
{
    //base case
    if(i>j)
        return true;

    if(str[i]!=str[j])
        return false;
    else
        //Recursive call
        return checkPalindrome(str,i+1,j-1);        
}
int main()
{
    string str="abbcacbba";
    if(checkPalindrome(str,0,str.length()-1))
        cout<<"Yes its Palindrome"<<endl;
    else
        cout<<"No,not Palindrome"<<endl;   

    return 0;
}