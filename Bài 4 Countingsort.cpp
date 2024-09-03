#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;
int main (){
    
    ios_base::sync_with_stdio(false);
    
    int n ;
    cin>>n;
    vector<pair<int, string>> data (n) ;
     /***Cách 1
    for(int i=0 ; i<n;i++){
        
        cin>>data[i].first>>data[i].second ;
         if (i < n / 2) {
            data[i].second = "-";
        }
    }
     stable_sort(data.begin(), data.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        return a.first < b.first;  
    });
     for (const auto& p : data) {
        cout << p.first << " " << p.second << endl;
    }
   ***/
// Cách 2 
   for(int i=0 ; i<n;i++){
        
        cin>>data[i].first>>data[i].second ;
       if (i < n / 2) {
            data[i].second = "-";
        }
    }
    
    vector <int> position (101,0);
    vector <int> count (101,0) ;
    
    for (const auto &pair : data){
        count[pair.first]++; 
    }
    
    for (int i=1 ; i<=100 ;i++){
        position[i] = position[i-1] + count[i - 1];
    }
    
    vector<pair<int , string>> result(n) ;
    
    for (const auto & pair : data){
        result[position[pair.first]++] = pair ;
    }
    
    for (const auto &pair : result){
        cout<<pair.first<<" " << pair.second<<endl;
    }
    
    return 0 ;
    }
      
