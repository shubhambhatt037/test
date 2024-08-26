#include <iostream>
using namespace std;
void sortArray(int *arr, int n)
{
    // base case
    if (n == 0 || n == 1)
        return;

    //Recursive call
    sortArray(arr,n-1);

    int j = n - 2;
    int temp = arr[n - 1];
    while (temp < arr[j] && j >= 0)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = temp;
}
int main()
{
    int arr[5]={1009,55,2,109,69};
    sortArray(arr,5);
    for(int i=0;i<5;i++)
        cout<<arr[i]<<endl;

    return 0; 
}