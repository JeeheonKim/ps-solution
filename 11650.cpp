#include <iostream>
#include <vector>
#include <utility>
using namespace std;
void print(vector<pair<int, int>> v, int a, int b) {
    for (int i=a; i<=b; ++i) cout << v[i].first << " " << v[i].second << '\n';
}

int merge(vector<pair<int, int>> &v, int start, int mid, int end){
    int a=start, b=mid+1, t=0;
    vector<pair<int,int>> temp;
    temp.resize(end-start+1);    
    while(a<=mid && b<=end){
        if(v[a].first > v[b].first) temp[t++] = v[b++];
        else if(v[a].first < v[b].first) temp[t++] = v[a++];
        else {
            if(v[a].second < v[b].second) {
                temp[t++] = v[a++];
                temp[t++] = v[b++];
            } else {
                temp[t++] = v[b++];
                temp[t++] = v[a++];                
            } 
        }
    }

    if (b > end) {
        while(a<=mid) temp[t++] = v[a++];
    } else {
        while(b<=end) temp[t++] = v[b++];
    }

    t=0;
    for (int i=start; i<=end; ++i){
        v[i] = temp[t++];
    }
}
int mergeSort(vector<pair<int, int>> &v, int start, int end){
    if (start < end){
        int mid = (start+end)/2;

        mergeSort(v, start, mid);
        mergeSort(v, mid+1, end);
        merge(v, start, mid, end);
    }
}

int main(){
    vector<pair<int,int>> v;
    int N;
    cin >> N;
    for(int i=0; i<N; ++i){
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    
    mergeSort(v,0, N);
    print(v,0, N-1);

}