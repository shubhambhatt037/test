#include<iostream>
using namespace std;

bool linearSearch(int arr[],int size,int ele)
{
    if(size==0)
        return 0;

    if(arr[0]==ele)  
        return 1;  

    linearSearch(arr+1,size-1,ele);    

}
int main()
{
    int arr[5]={2,3,5,7,9};
    int ele;
    cout<<"\nEnter element to be searched-> ";
    cin>>ele;
    if(linearSearch(arr,5,ele))
        cout<<"\nElement is present"<<endl;
    else
        cout<<"\nElement not present"<<endl;

    return 0;        

}