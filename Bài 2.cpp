#include <iostream>
#include <algorithm>

using namespace std ;
int partition (int * arr , int left , int right){
    int res[1000] ;
    int temp = 0  ;
    int pivot = arr[left];
    
    for (int i =left+1 ; i <= right ; i++)
       if (arr[i] <= pivot)
         res[temp++] = arr[i];
     res[temp++] = pivot ;
    
    
    int found = temp - 1 + left ;
    for (int i=left+1 ; i <= right ; i++)
        if (arr[i] > pivot)
           res[temp++] = arr[i];
    
    for (int i= left ; i<= right ;i++)
        arr[i] = res[i-left];
    
    return found;
}
void quicksort (int *arr , int left , int right){
    if (left < right){
        int phanvung = partition(arr ,left ,right);
        quicksort(arr , left , phanvung-1 );
        quicksort(arr ,phanvung+1 , right);
    
    for (int i=left ; i <= right ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
}
int main(){
    int n ;
    
    cin>>n;
    
    int arr[n];
    
    for (int i=0 ; i<n ;i++){
        cin>>arr[i];
    }

     quicksort (arr , 0 , n-1);

    return 0;
}
