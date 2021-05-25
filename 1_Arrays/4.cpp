#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <utility>

#define fast                sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

// sort 1's, 2's and 3's
// soln :- using 2 pointers, l starts from 0 and r starts from n-1
// and a third pointer to traverse until < r

void print(const vector<int> a){
    for (int i=0 ; i<a.size() ; i++)    cout << a[i] << " ";
    cout << endl;
}

int main(){
    int n = 10;
    vector<int> a {1, 2, 3, 2, 1, 2, 3, 3, 2, 1};

    //int n;      //cin >> n;
    //vector<int> a(n);          for(int i=0 ;i<n ;i++)      cin >> a[i];

    int l =0, r = n-1;

    for (int i=0 ;i<r ;i++){                // crux :- i<r 
        if (a[i] == 1){
            swap(a[l++], a[i]);
        }
        else if(a[i] == 3){
            swap(a[i--], a[r--]);           // crux :- i--
        }
    }

    // int i=0;
    // while(i<r){
    //     if (a[i] == 1){
    //         swap(a[i++], a[l++]);
    //     }
    //     else if(a[i] == 3){
    //         swap(a[i], a[r--]);
    //     }
    //     else{
    //         i++;
    //     }
    //     //cout << i << "    ";
    //     //print(a);
    // }
    
    print(a);
    return 0;
}