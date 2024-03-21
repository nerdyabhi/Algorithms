#include <iostream>
using namespace std;

void max_min(int arr[] , int &max1 , int &min1 , int s , int e )
{

    if(s==e)
    {
        max1 = min1 = arr[s];return;
    }

    else if(e == s+ 1)
    {
        max1 = max(arr[s], arr[e]);
        min1 = min(arr[s], arr[e]);
    }

    else{
        int mid = (s+(e-s)/2);
        int max_1 , max_2 , min_1 , min_2;

        max_min(arr , max_1 , min_1 , s , mid);        
        max_min(arr , max_2 , min_2 , mid , e);     

        max1 = max(max_1 , max_2);   
        min1 = min(min_1 , min_2);   
    }

}
int main()
{
    int arr[] = {1 , 2, 3, 4, 5, 6, 7 ,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max1 =0 , min1=0;
    max_min(arr ,max1 , min1 , 0 , n-1);

    cout<<"Max : " <<max1  <<" , Min : " <<min1<<endl;
    return 0;
}