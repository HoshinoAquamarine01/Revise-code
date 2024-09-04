#include <iostream>
#include <vector> 

using namespace std ;

int main (){
    
    ios_base::sync_with_stdio(false);
    
    int n ;
    cin>>n;
    
    vector <int> arr(n);
    vector <int> count (1000,0);
    
    for (int i =0 ; i<n;i++){
        cin>>arr[i];
        count[arr[i]]++ ;
    }
    
    int min = 0 ;
    
    for (int i=0 ; i<n;i++){
        
        if (arr[i] < min){
            min = arr[i];
        }
    }
    
    for (int i = min ; i <= n ; i++){
        if (count[i] ==0){
            cout<<i<<" ";
        }
    }
    
    return 0 ;
}
