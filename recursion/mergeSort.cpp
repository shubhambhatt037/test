#include <iostream>
using namespace std;
void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int index1 = 0;
    int index2 = 0;

    int mainArrayIndex = s;

    for (index1 = 0; index1 < len1; index1++)
        first[index1] = arr[mainArrayIndex++];

    mainArrayIndex = mid + 1;

    for (index2 = 0; index2 < len2; index2++)
        second[index2] = arr[mainArrayIndex++];

    mainArrayIndex = s;
    index1 = 0;
    index2 = 0;

    while(index1 < len1  && index2 < len2)
    {
        if(first[index1]<second[index2])
            arr[mainArrayIndex++]= first[index1++];

        else   
            arr[mainArrayIndex++]= second[index2++];   
    }

    while(index1 < len1)
        arr[mainArrayIndex++]=first[index1++];

    while(index2 < len2)
        arr[mainArrayIndex++]=second[index2++];

    delete []first;
    delete []second;    
}

void mergeSort(int *arr, int s, int e)
{
    // base case
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;
    // sorting left part
    mergeSort(arr, s, mid);

    // sorting right part
    mergeSort(arr, mid + 1, e);

    // merge
    merge(arr, s, e);
}
int main()
{
    int arr[5]={1009,55,2,109,69};
    mergeSort(arr,0,4);
    for(int i=0;i<5;i++)
        cout<<arr[i]<<endl;

    return 0; 
}