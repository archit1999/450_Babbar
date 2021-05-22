// copyright @babaji
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <utility>

#define fast                sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

// find min & max in minimum number of comparisons

pair<int, int> min_max(vector<int> a, int l, int r){
    if(l >= r)
        return make_pair(a[l], a[l]);
    
    int mid = l + (r-l)/2;
    pair<int, int> p1 = min_max(a, l, mid);
    pair<int, int> p2 = min_max(a, mid+1, r);

    return make_pair(min(p1.first, p2.first), max(p1.second, p2.second));
}

int main(){
    int n = 5; //cin >> n;
    vector <int> a {1, 2, 3, 4, 5}; 
    //for (int i=0 ; i<n ;i++)    cin >> a[i];

    pair<int, int> x= min_max(a, 0, n-1);
    cout << x.first << " " << x.second  ;
}
