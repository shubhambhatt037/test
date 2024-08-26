#include<iostream>
using namespace std;
int main()
{
    int arr[10],n,min=0;
    cout<<"\nEnter number of elements -> ";cin>>n;
    cout<<"\nEnter array elements->"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int temp,pos;
    for(int i=0;i<n-1;i++)
    {
        min=arr[i];
        for(int j=i+1;j<n;j++)
        {
            if(min>arr[j])
            {
                pos=j;
                min=arr[j];
            }
        }
        if(min!=arr[i])
        {
            temp=arr[i];
            arr[i]=arr[pos];
            arr[pos]=temp;
        }
    }
    cout<<"\nNew array->"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}