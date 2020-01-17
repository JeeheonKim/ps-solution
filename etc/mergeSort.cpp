// give the number of element
// and its elements (separated by space)
#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& arr, int start, int mid, int end){
    int a=0, b=mid+1, i=0;
    int tmp[50000];
    while (a<mid && b<end){
        if (arr[a] < arr[b]) {
            tmp[i++] = arr[a++];
        } else if (arr[b] < arr[a]) {
            tmp[i++] = arr[b++];
        } else {
            tmp[i++] = arr[a++];
            tmp[i++] = arr[b++];
        }
    }

    if (a>=mid) {
        while (b<end){
            tmp[i++] = arr[b++];
        }
    }

    i=0;
    for (auto& a: arr)
        a = tmp[i++] ;
}

int mergeSort(vector<int>& arr, int start, int end){
    if (start<end){
        int mid = (start-end)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, end, mid);
        return 0;
    }
}

int print(vector<int> v) {
    for (auto a : v){
        cout << a << " ";
    }
}

int main(){
    int N, tmp;
    vector<int> v;
    cin >> N;
    for (int i=0; i<N; ++i){
        cin >> tmp;
        v.push_back(tmp);
    }

    mergeSort(v, 0, N-1);
    print(v);

    return 0;
}