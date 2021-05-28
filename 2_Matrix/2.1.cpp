#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <utility>


using namespace std;

// transpose of a matrix

void print(vector<vector<int>> a){
    for (int i=0 ; i<a.size() ;i++){
        for (int j=0 ;j<a[0].size() ;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void transpose(vector<vector<int>> &a, int n){
    for (int i=0 ; i<n ;i++){
        for(int j=i+1 ; j<n ;j++){
            swap(a[i][j], a[j][i]);
        }
    }
}

int main(){

    // int n;          cin >> n;
    // vector<vector<int>> a(n, vector<int>(n));
    // for (int i=0 ;i<n ;i++) for(int j=0 ;j<n ;j++)      cin >> a[i][j];

    // uncomment above part to take input & also comment below part

    int n = 4; 
    vector<vector<int>> a { {1, 2, 3, 4},
                            {5, 6, 7, 8},
                            {9, 10, 11, 12},
                            {13, 14, 15, 16} };

    transpose(a, n);
    print(a);
}