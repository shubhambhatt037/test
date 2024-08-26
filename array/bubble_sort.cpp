#include<iostream>
using namespace std;
int main()
{
    int arr[10],n;
    cout<<"\nEnter number of elements-> ";cin>>n;
    cout<<"\nEnter array elements->";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        int temp=0;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[j-1])
            {
                temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
    cout<<"\nSorted array->"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}