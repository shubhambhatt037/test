#include<iostream>
using namespace std;
bool linsearch(int arr[],int size,int key)
{
    for(int i=0;i<size;i++)
    {
        if(key==arr[0])
            return 1;    
    }
    return 0;
}
int main()
{
    int arr[5]={12,16,5,7,9};
    int key;
    cout<<"\nEnter the element to be searched->"<<endl;cin>>key;
    bool found=linsearch(arr,5,key);
    if(found)
        cout<<"The number is present"<<endl;
    else
        cout<<"the number is not present"<<endl;    
    return 0;
}