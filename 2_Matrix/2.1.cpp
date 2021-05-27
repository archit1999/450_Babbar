#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <utility>

#define fast                sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

// spiral traversal of matrix

int main(){
    int rows = 5, cols = 3;

    vector<vector<int>> a { {1, 2, 3},
                            {5, 6, 7 },
                            {9, 10, 11},
                            {40, 41, 42},
                            {43, 44 , 45}};

    for (int i=0 ;i<rows/2 && i<cols/2 ;i++){        // layer's loop

        // 1st row of this layer
        for (int j=i; j < cols - i ;j++)          
            cout << a[i][j] << " ";

        // last col for this layer
        for (int j = i+1; j< rows - i;j++){
            cout << a[j][cols - i - 1]  << " ";
        }

        // last row of this layer
        for(int j = cols - i -2 ; j >= i ; j--){
            cout << a[rows - i - 1][j] << " ";
        }

        // first col of this layer
        for (int j=rows-i-2 ; j>i ;j--){
            cout << a[j][i] << " ";
        }
    }

    if (rows < cols && rows%2 == 1){
        for(int i= rows/2 ; i < cols - rows/2 ;i++){
            cout << a[rows/2][i] <<  " ";
        }
    }
    if (cols < rows && cols %2 == 1){
        for (int i=cols/2 ; i < rows - cols/2 ;i++){
            cout << a[i][cols/2] << " ";
        }
    }
    cout << endl;
    return 0;
}