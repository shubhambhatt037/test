#include<iostream>
using namespace std;
bool bSearch(int arr[],int s,int e,int k)
{
    if(s>e)
        return false;

    int mid= s + (e-s)/2;

    if(arr[mid]==k)
        return true;

    if(arr[mid]<k)
        return bSearch(arr,mid+1,e,k);
    else
        return bSearch(arr,s,mid-1,k);
       

}
int main()
{
    int arr[5]={2,5,7,9,13};
    int k;
    cout<<"Enter element to be searched"<<endl;
    cin>>k;
    int s=0;
    int e=4;
    if(bSearch(arr,s,e,k))
        cout<<"Element is present"<<endl;
    else
        cout<<"Element not present"<<endl;
    return 0;
}