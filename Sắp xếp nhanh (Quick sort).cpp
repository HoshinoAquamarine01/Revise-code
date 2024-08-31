#include <iostream>
using namespace std;

void quicksort (int arr[] , int left , int right){
    int pivot = arr[(left + right)/2];

    int i = left ;
    int j = right ;
    int temp ;

    while (i <= j){

        while (arr[i] < pivot) 
        i++;

        while (arr[j] > pivot)
        j-- ;

        if (i <= j){
            temp = arr[i];
            arr[i]= arr[j];
            arr[j]= temp;
            i++;
            j--;
        }
        if (left < j){
            quicksort(arr, left, j);
        }
        if (right > i){
            quicksort(arr, i, right);
        }
}
}
int main (){
    int n ;
    cin>>n;

    int arr[n];

    for (int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    quicksort(arr, 0, n-1);

    for(int i =0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
}
