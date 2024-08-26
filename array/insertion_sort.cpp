#include<iostream>
using namespace std;
int main()
{
    int arr[10],n;
    cout<<"\nEnter number of elements->";cin>>n;
    cout<<"\nEnter elements of the array-> "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<n;i++)
    {
       // int pos=i;                               
		int temp=arr[i];
		int j=i-1;
		while(temp<arr[j]&&j>=0)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
    }
    cout<<"\nSorted array->"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}