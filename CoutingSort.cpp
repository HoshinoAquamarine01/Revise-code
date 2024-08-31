#include <iostream>
#define array_size 10
#define max_num 10 
using namespace std;
int i ; 
void countingsort (int *arr){
   int result[max_num] = {0};

   for (int i = 0; i < array_size ; i++)
          result[arr[i]]++ ;
     int out = 0 ;

     for (int i = 0; i < max_num ; i++)
     while (result[i]--)
       arr[out++] = i ;
   
}
int main (){
    ios_base::sync_with_stdio(false);
   int arr[array_size] = { 2, 5, 3, 7, 3, 9, 8, 7, 3, 1 };
    countingsort(arr);
    for(int i =0 ; i < array_size ; i++){
        cout<<arr[i]<<" ";
    }
}
