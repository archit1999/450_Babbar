// copyright @babaji
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <utility>

#define fast                sync_with_stdio(false); cin.tie(null); cout.tie(null);

using namespace std;

// find kth smallest number in an array, in O(n) time, and O(1) space
// soln :- 
// so the logic here is to use quicksort but only partially, that is choose the pivot put it
// in correct place, and ercursively choose either the left or right part only.
// its average linear time, but in worst case takes O(n^2)
// so we use the median of median algo, in which we find a pivot element, which is atleast 
// greater than 3n/10 elements and simalarly smaller by 3n/10 elements, so gives linear time solution. 

void print(vector<int> a){
    for (int i=0 ; i<a.size() ;i++)    cout << a[i] << " ";
    cout << endl;
}

int median(vector<int> a){
    sort(a.begin(), a.end());
    return a[a.size()/2];
}

int medianOfMedian(vector<int> arr, int l, int r){
    vector<int> medians;
    for (int i=l ; i < r ; i = i+5){
        vector<int> a;
        for (int j=0 ; j<5 && (i+j) < r ;j++){
            a.push_back(arr[i+j]);
        }
        //print(a);
        medians.push_back(median(a));
    }
    //print(medians);
    if (medians.size() == 1){
        return medians[0];
    }
    return medianOfMedian(medians, 0, medians.size());
}

int quickSearch(vector<int> a, int l, int r, int k){        // r is an index of next to last element
    int pivot = medianOfMedian(a, l, r);
    int x = l, pivot_index;

    for (int i = l ; i<r ;i++){
        if (a[i] < pivot){
            swap(a[i], a[x]);
            x++;
        }
    }
    for (int i=l ;i<r ;i++){
        if (a[i] == pivot)
            pivot_index = i;
    }
    swap(a[x], a[pivot_index]);

    if(pivot_index == k-1){
        return a[pivot_index];
    }
    else if (pivot_index < k){
        return quickSearch(a, pivot_index+1, r, k - (pivot_index - l) );
    }
    else{
        return quickSearch(a, l, pivot_index, k);
    }
}

int main(){
    int n = 12;
    vector<int> arr {17, 2, 12, 4, 9, 3, 1, 7, 14, 21, 42, 5};

    quickSearch(arr,0, n, 3);
    return 0;
}
