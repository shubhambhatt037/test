#include<iostream>
using namespace std;

void strReverse(string &str,int i,int j)
{
    //base case
    if(i>j)
        return;

    swap(str[i],str[j]);
    i++;
    j--;

    //Recursive case 
    strReverse(str,i,j);

}
int main()
{
    string name="babbar";
    strReverse(name,0,name.length()-1);
    cout<<name<<endl;
    return 0;
}