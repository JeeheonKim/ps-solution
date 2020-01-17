// give the number of element
// and its elements (separated by space)
#include <iostream>
#include <vector>
using namespace std;

int print(vector<int> v) {
    for (auto a : v){
        cout << a << " ";
    }
    cout << '\n';
}

int merge(vector<int>& arr, int start, int mid, int end){
    int a=start, b=mid+1, i=0;
    int tmp[1000];

    while (a<=mid && b<=end){
        if (arr[a] <= arr[b]) {
            tmp[i++] = arr[a++];
        } else if (arr[b] < arr[a]) {
            tmp[i++] = arr[b++];
        } 
        else {
            tmp[i++] = arr[a++];
            tmp[i++] = arr[b++];
        }
    }

    if (a>mid) { //first array is empty
        while (b<=end){
            tmp[i++] = arr[b++];
        }
    } else {
        while (a<=mid){
            tmp[i++] = arr[a++];
        }
    }

    i=0;
    for (int j=start; j<=end; ++j)
        arr[j] = tmp[i++];
        
    return 0;
}

int mergeSort(vector<int>& arr, int start, int end){
    int mid = (start+end)/2;

    if (start<end){
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
    return 0;
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