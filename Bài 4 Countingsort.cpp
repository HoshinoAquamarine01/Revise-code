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
    }
     stable_sort(data.begin(), data.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        return a.first < b.first;  
    });
     for (const auto& p : data) {
        cout << p.first << " " << p.second << endl;
    }
   ***/
// Cách 2 sẽ cập nhật sau
