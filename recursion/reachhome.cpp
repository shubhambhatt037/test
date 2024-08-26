#include<iostream>
using namespace std;
void reachhome(int dest,int src)
{
    cout<<"Source "<<src<<" Destination "<<dest<<endl;
    //base case
    if(src==dest){
        cout<<" Pouch gya "<<endl;
        return ;
    }
    
    //Processing..ek step aage bad jao
    src++;

    //Recursive call
    reachhome(dest,src);
}

int main()
{
    int dest=10,src=0;

    reachhome(dest,src);
    return 0;
}