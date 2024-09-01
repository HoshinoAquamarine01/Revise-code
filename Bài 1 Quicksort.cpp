#include <iostream>
using namespace std ;
int main (){
    int n ; 


    cin >> n ;
    
    int arr[n] , left[n] , right[n] , equal[n];

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i] ;
    }
    int pivot = arr[0] ;

    int l = 0 , r = 0 , e = 0 ;
    for (int i=0 ;  i <n ; i++){
        if (arr[i] > pivot){
            right[r] = arr[i] ;
             r++;
        }
        else if (arr[i] < pivot){
            left[l] = arr[i] ;
             l++;
        }
        else {
            equal[e] = arr[i] ;
             e++;
    }
    }
    for (int i=0 ; i < l; i++){ cout<<left[i]<<" ";}
    for (int i=0 ; i < e; i++){ cout<<equal[i]<<" ";}
    for (int i=0 ; i < r; i++){ cout<<right[i]<<" ";}
    return 0 ;
}
