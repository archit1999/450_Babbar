// copyright @babaji
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

#define fast                ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

// Reverse the array

void print(const vector<int> a){
    for (int i=0 ; i<a.size() ; i++)    cout << a[i] << " ";
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
