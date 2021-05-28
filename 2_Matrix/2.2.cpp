#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <utility>

using namespace std;

// rotate a matrix n number of times clockwise
// for anticlockwise, multiply rotations by 3

void print(vector<vector<int>> a){
    for (int i=0 ; i<a.size() ;i++){
        for (int j=0 ;j<a[0].size() ;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void rotate_clockwise(vector<vector<int>> &a, int n, int rotations){

    rotations %= 4;
    
    while(rotations--){
        for(int i=0 ;i<n/2 ; i++){              // onion layer
            for (int j=i ; j< n-i-1 ;j++){

                int temp1 = 0, temp2 = 0;
                
                temp1 = a[j][n-i-1];
                a[j][n-i-1] = a[i][j];

                temp2 = a[n-i-1][n-j-1];
                a[n-i-1][n-j-1] = temp1;

                temp1 = a[n-j-1][i];
                a[n-j-1][i] = temp2;

                a[i][j] = temp1;  
            }
        }
    }
}

void rotate_anti(vector<vector<int>> &a, int n, int rotations){
    rotate_clockwise(a, n, 3 * rotations);
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

    int rotations = 4;
    rotate_clockwise(a, n, rotations);
    print(a);
}