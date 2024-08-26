#include<iostream>
using namespace std;

void revarr(int arr[],int size)
{
    int temp;
    for(int i=0,j=size-1;i<=j;i++,j--)
    {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
}
int main()
{
    int arr[5]={5,4,3,2,1};
    revarr(arr,5);
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<endl;
    }
    
    return 0;
}