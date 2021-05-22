// copyright @babaji
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

#define fast                sync_with_stdio(false); cin.tie(null); cout.tie(null);

using namespace std;

// Reverse the array

void print(const vector<int> a){
    for (int i=0 ; i<a.size() ; i++)    cout << a[i] << endl;
    cout << endl;
}

int main(){
    fast;
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0 ; i<n ;i++)    cin >> a[i];

    reverse(a.begin(), a.end());
    print(a);

    return 0;
}