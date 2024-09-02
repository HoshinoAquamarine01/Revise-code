#include <iostream>
#include <vector>

using namespace std ;

int main (){
    int n ; 
    cin>>n; 
    
    vector <int> arr (n);
    vector <int> count (100,0);
    
    for (int i=0 ; i < n ; i++){
        cin>>arr[i];
        count[arr[i]]++;
    }
    
    for (int i =0 ; i < n ; i++){
        cout<<count[i]<<" ";
    }
    
    return 0 ;
}
