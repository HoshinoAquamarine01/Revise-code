#include<iostream>
#include<vector>

using namespace std;

int binarySearch(vector<int> arr, int left, int right, int key)
{
    while (right-left > 1) {
        int m = left + (right-l)/2;
        if (arr[m] >= key) right = m;
        else left = m;
    }
    return right;
}


int main ()
{
   ios_base::sync_with_stdio(false) ;
    int key, n;
    
    cin >> n >> key;
    
    vector<int> arr(n);
    
    for (int i = 0 ; i < n ; i++)
        cin >> arr[i] ;
    
    sort(arr.begin(), arr.end());
    
    cout << binarySearch(vc, -1, n-1, key) << endl;
    
    return 0;
}
