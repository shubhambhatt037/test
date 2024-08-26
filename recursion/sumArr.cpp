#include<iostream>
using namespace std;
int sum=0;
int sumArr(int arr[],int size)
{
    if(size==0)
        return sum;

    sum+=arr[0];

    sumArr(arr+1,size-1);

}
int main()
{
    int arr[5]={2,5,7,9,13};
    
    cout<<"\nSum of array elements is-> "<<sumArr(arr,5)<<endl;
    return 0;
}