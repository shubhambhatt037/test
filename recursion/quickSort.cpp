#include<iostream>
using namespace std;
int partition(int arr[],int s,int e)
{
    int pivot = arr[s];

    int count=0;
    for(int i=s+1;i<=e;i++)
        if(arr[i]<=pivot)
            count++;

    //place pivot at right position
    int pivotindex = s+count;
    swap(arr[pivotindex],arr[s]);

    int i=s,j=e;
    while(i < pivotindex && j > pivotindex)
    {
        while(arr[i] <= arr[pivotindex])
            i++;

        while(arr[j] > arr[pivotindex])
            j--;

        if(i < pivotindex && j > pivotindex)
            swap(arr[i++],arr[j--]);        
    }

    return pivotindex;
}

void quickSort(int arr[],int s,int e)
{
    //base case
    if(s>=e)
        return;

    int p=partition(arr,s,e);

    //sort left part
    quickSort(arr,s,p-1);

    //sort right part
    quickSort(arr,p+1,e);    
}
int main()
{
    int arr[5]={55,68,23,1,10};
    quickSort(arr,0,4);
    for(int i=0;i<5;i++)
        cout<<arr[i]<<endl;

    return 0; 
}