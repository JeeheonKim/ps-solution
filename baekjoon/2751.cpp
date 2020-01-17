#include <iostream>
#include <vector>
using namespace std;
#define print(a, N)  for(int i=0; i<N; ++i) cout << a[i] << '\n'
#define enter cout << '\n'
void merge(vector<int> &a, int start, int mid, int end){
    int i=start, j = mid+1, t = 0;
    int *temp = new int[end-start+1];
    
    //두 배열 중 하나의 모든 원소가 temp에 들어갈 때까지 
    while ( i<= mid && j <= end) {
        if (a[i] <= a[j]) temp[t++] = a[i++];
        else temp[t++] = a[j++];
    }

    if (i > mid) {
        for (int k=j; k<=end; ++k) temp[t++] = a[k];
    }
    else {
        for (int k=i; k<=mid; ++k) temp[t++] = a[k];
    }

    t = 0;
    for(int i=start; i<=end; ++i) a[i] = temp[t++];

    //print(a, start-end-1);
    delete[] temp;
}

void mergeSort(vector<int> &a, int start, int end){
    if (start < end) {
        int mid = (start + end)/2;
        mergeSort(a, start, mid);
        mergeSort(a, mid+1, end);
        merge(a, start, mid, end);
    }
}

int main(){
    int N;
    vector<int> a;

    cin >> N; 
    for(int i=0; i<N; ++i) {
        int temp;
        cin >> temp;
        a.push_back(temp); 
    }

    mergeSort(a, 0, N-1);

    print(a, N);

    return 0;
}
