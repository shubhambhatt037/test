#include<iostream>
using namespace std;
void sortArray(int *arr,int n)
{
    if(n==0 || n==1)
        return ;

    int pos;    
    for(int i=0;i<n-1;i++)
    {
        int min=arr[i];
        if(min>arr[i+1]){
            pos=i+1;
            min=arr[i+1];
            sortArray(arr+i+1,n-(i+1));
        }        
        if(arr[i]!=min)
            swap(arr[i],arr[pos]);
    }
}
int main()
{
    int arr[5]={1009,55,2,109,69};
    sortArray(arr,5);
    for(int i=0;i<5;i++)
        cout<<arr[i]<<endl;

    return 0;    
}