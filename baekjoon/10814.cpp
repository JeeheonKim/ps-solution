#include <iostream>
#include <utility>
#include <vector>
#include <string>
using namespace std;
#define vp vector<pair<int, string>>

int print(vp v, int n){
    cout <<"*" <<endl;
    for (int i=0; i<n; ++i) {
        cout << v[i].first << " " << v[i].second << '\n';
    }
}

void merge(vp & v, int start, int mid, int end){
    int a = 0, b=0, t=0;
    vp temp;
    temp.resize(end-start+1);

    while (a<=mid && b<=end){
        if (v[a].first < v[b].first) temp[t++] = v[a++];
        else temp[t++] = v[b++];
    }

    if (a > mid) {
        for (int i=b; i<=end; ++i){
            v[i] = temp[t++];
        }
    } else {
        for (int i=a; i<=mid; ++i){
            v[i] = temp[t++];
        }
    }

    t=0;
    
    for (int i=start; i<=end; ++i){
        v[i] = temp[t++];
    }

    print(v, end-start+1);
}

void mergeSort(vp & v, int start, int end){
    if (start<end){
        int mid = (start+end)/2;
        mergeSort(v, start, mid);
        mergeSort(v, mid+1, end);
        merge(v, start, mid, end);
    }
}

int main(){
    int N;
    vp v;
    cin >> N;

    for(int i=0; i<N; ++i){
        string name; int age;
        cin >> age >> name;
        v.push_back(make_pair(age, name));
    }

    mergeSort(v, 0, N-1);

    print(v, N);
}