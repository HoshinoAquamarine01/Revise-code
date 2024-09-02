#include <iostream>
#include <vector>

using namespace std ;
int main (){
     ios_base::sync_with_stdio(false);
    vector <int> count(100,0);
    
    int n ;
    cin>>n;
    
    for (int i=0 ; i<n;i++){
        int num;
        
        string index ;
        
        cin>>num>>index;
        
        count[num]++;
        
    }
    vector <int> kq (100,0);
    
    kq[0] = count[0];
    
    for (int i=1 ; i<=100;i++){
        
        kq[i] = kq[i-1] + count[i];
    }
    for (int i=0 ; i<=100;i++){
        
        cout<<kq[i]<<" ";
    }
}
