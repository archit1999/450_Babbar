#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <utility>

#define fast                sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

// find the first and last index of given element x in a sorted array.

void print(vector<int> a){
    for (int i=0 ; i<a.size() ;i++)    cout << a[i] << " ";
    cout << endl;
}

int next(int l, int r, int x, vector<int> a){

    // returns the last index where x can be inserted in a to keep it sorted.
    // 0 based index returned

    int mid = l + (r-l)/2;

    if (l >= r){
        if (a[l] > x)
            return l;
        else
            return l+1;
    }
    // for choosing l or r, think of a of size 2 & solve for both sides.
    // here I needed r so took it.

    if (a[mid] > x){
        return next(l, mid-1, x, a);
    }
    else{
        return next(mid+1, r, x, a);
    }
}

vector<int> firstAndLast(vector<int> a, int x){
    int first = next(0, a.size() - 1, x-1, a);      // first place for x is the last place for x-1
    int second = next(0, a.size() - 1, x, a);   
    second--;                                       // last place for x is -1 place for new x

    vector<int> ans(2);
    if (second < first){
        ans[0] = ans[1] = -1;
    }
    else{
        ans[0] = first;     ans[1] = second;
    }
    return ans;
}

int main(){
    // int n;  cin >> n;
    // vector<int> a(n);   for(int i=0 ; i<n ;i++)     cin >> a[i];

    int n = 9;
    vector<int> a { 1, 3, 5, 5, 5, 5, 67, 123, 125 };
    int x = 5;

    // int n = 2;
    // vector<int> a {6, 9};
    // int x = 9;
    
    vector<int> ans = firstAndLast(a, x);
    //cout << next(0, a.size() -1, x, a) << " " << next(0, a.size() -1, x-1, a) << endl;
    print(ans);

    return 0;
}