#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define y "YES"

int print(vector<int> v) {
    cout <<"elements are -- ";
    for(auto & a: v){
        cout << a<< " ";
    }
    cout <<'\n';
}

int evaluate(vector<int> p, int l, int r, int q){
    if ( l == r || r < q) return 1;
    // sort is not working well..?
//...?
    int idx = l; int a = p[q];
    for (int i=l; i<=r; ++i){
        if (a > p[i]) {
            idx ++;
        }    
    }
    //cout << a << "\'s idx: " << q << " after sorting: " << idx <<'\n';
    if (idx == q)
        return 1;
    return 0;
}

int main(){
    int n, m;
    vector<int> p;
    cin >> n >> m;
    
    int tmp;
    for (int i=0; i<n; ++i){
        cin >> tmp;
        p.push_back(tmp);
    }

    int l, r, q;
    for (int i=0; i<m; ++i){
        cin >> l >> r >> q;
        l--; r--; q--;
        cout << (evaluate(p, l, r, q) ? "Yes" : "No") << '\n';
    }


}