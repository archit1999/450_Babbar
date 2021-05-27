#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <utility>

#define fast                sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

// spiral traversal of matrix

void print(vector<int> a){
    for (int i=0 ; i<a.size() ;i++)    cout << a[i] << " ";
    cout << endl;
}

vector<int> spirallyTraverse(int rows, int cols, vector<vector<int>> a){
    vector<int> ans(rows*cols);   int a_index = 0;

    for (int i=0 ; i < rows/2 && i < cols/2 ;i++){        // layer's loop

        // 1st row of this layer
        for (int j=i; j < cols - i ;j++)          
            ans[a_index++] = a[i][j]; 

        // last col for this layer
        for (int j = i+1; j< rows - i;j++){
            ans[a_index++] =  a[j][cols - i - 1] ;
        }

        // last row of this layer
        for(int j = cols - i -2 ; j >= i ; j--){
            ans[a_index++] =  a[rows - i - 1][j] ;
        }

        // first col of this layer
        for (int j=rows-i-2 ; j>i ;j--){
            ans[a_index++] = a[j][i];
        }
    }

    if (rows < cols && rows%2 == 1){
        for(int i= rows/2 ; i < cols - rows/2 ;i++){
            ans[a_index++] = a[rows/2][i];
        }
    }
    if (cols <= rows && cols %2 == 1){
        for (int i=cols/2 ; i < rows - cols/2 ;i++){
            ans[a_index++] =  a[i][cols/2];
        }
    }
    return ans;
}

int main(){
    int rows = 5, cols = 3;

    vector<vector<int>> a { {1, 2, 3},
                            {5, 6, 7 },
                            {9, 10, 11},
                            {40, 41, 42},
                            {43, 44 , 45}};

    
    vector<int> ans = spirallyTraverse(rows, cols, a);
    print(ans);
    return 0;
}