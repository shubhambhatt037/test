#include<iostream>
using namespace std;
int bsearch(int arr[],int n,int key)
{
    int mid,strt=0,ed=n-1;
    while (strt<=ed)
    {
        mid=(strt+ed)/2;
        if(mid==key)
        {
            return mid;
        }else if(key<mid){
            ed=mid-1;
        }else if(key>mid){
            strt=mid+1;
        }
    }
    return -1;
}
int main()
{
    int arr[10],n,key;
    int x=0;
    cout<<"\n Enter number of elements->";cin>>n;
    cout<<"\nEnter elements->";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"\n Enter key->";cin>>key;
    x=bsearch(arr,n,key);
    cout<<"\nElement is present in "<<x<<" position"<<endl;
    return 0;
}