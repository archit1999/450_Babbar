#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <utility>

#define fast                sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int searchRotatedArray(vector<int> a, int x){
    int n = a.size();

    int l=0, r = n-1;
    int mid = l + (r-l)/2;
    while(l<r){
        mid = l+ (r-l)/2;

        if (a[mid] == x)
            return mid;

        else if (a[mid] > a[l]){              //l - mid   -> sorted
            if (a[mid] > x && a[l] <= x){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        else {
            if (a[mid] < x && a[r] >= x){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
    }

    if ( l >= 0 && l < n && a[l] == x)
        return l;
    if ( r>= 0 && r < n && a[r] == x)
        return r;
    
    return -1;
}

int main(){
    // int n;  cin >> n;
    // vector<int> a(n);   for(int i=0 ; i<n ;i++)     cin >> a[i];

    int n = 7;
    vector<int> a { 4,5,6,7,0,1,2 };
    int x = 4;

    cout << searchRotatedArray(a, x) << endl;
}