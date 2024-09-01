#include <iostream>
#include <algorithm>
using namespace std ;

int arr[1000], n ;

int patrition (int left , int right ){
    
    int p = right - 1 ;
    int w = left ;
    
    for (int i = left ; i <right ; i++){
        
        if (arr[i] < arr[p]){
            
          swap (arr[w] , arr[i]);
          w++ ;
        }
}
     swap(arr[w] , arr[p]);
 return w ;
}

void quicksort (int left ,int right){
    
    if (right -left <=1)
    return ;
    
    int p = patrition (left ,right);
    
    for (int i=0 ; i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    
    if (left < right){
        quicksort (left , p);
        
        quicksort (p+1 , right);
    }
}
int main (){
    
    cin>>n;
    for (int i=0 ; i<n;i++){
        cin>>arr[i];
    }
    quicksort (0,n);
}
