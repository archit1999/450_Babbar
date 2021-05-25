#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <utility>

#define fast                sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void print(const vector<int> a){
    for (int i=0 ; i<a.size() ; i++)    cout << a[i] << " ";
    cout << endl;
}

vector<int> merge(vector<int> a, vector<int> b){
    vector<int> c;
    int i=0, j=0;

    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]){
            c.push_back(a[i++]);
        }
        else{
            c.push_back(b[j++]);
        }
    }
    while (i < a.size())
        c.push_back(a[i++]);
    while (j < b.size())
        c.push_back(b[j++]);

    return c;
}

vector<int> mergesort(vector<int> a, int l, int r){
    if (l >= r){
        vector<int> c(1);
        c[0] = a[l];
        return c;
    }

    int mid = l + (r-l)/2;

    vector<int> y = mergesort(a, l, mid);
    vector<int> z = mergesort(a, mid+1, r);

    // print(y); print(z);
    return merge(y, z);
}

int main(){
    // int n;      cin >> n;
    // vector<int> a(n);   for (int i=0 ;i<n ;i++)     cin >> a[i];

    int n = 8;
    vector<int> a {5, 2, 3, 1, 7, 5, 0, 8};

    vector<int> b = mergesort(a, 0, n-1);
    print(b);
    
    return 0;
}