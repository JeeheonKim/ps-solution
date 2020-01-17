//욱제가 풀어야 하는 문제
// 그래프를 펴보면 다각형이 된다

#include <iostream>
using namespace std;
#define ll long long

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int T, v;
    cin >> T;
    for (int i=0; i<T; ++i){
        cin >> v;
        if (v == 1) {cout << 1 <<'\n'; continue;}
        else cout << 2 << '\n';
    }
    return 0;
}