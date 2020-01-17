//세그먼트는 원소 넣지말고 0-i 까지의 합을 넣으면 더 좋다
// https://github.com/shingiyeon/baekjoon/blob/master/2143.cpp 참고해서 품
//벡터를 쓰기가 꺼려진다. 왜일까..
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long 

void print(std::vector <int> const &a) {
   std::cout << "The vector elements are : ";
   
   for(int i=0; i < a.size(); i++)
      std::cout << a.at(i) << ' ';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T; int na, nb;
    cin >> T >> na;
    int a[1000001] = {0,};
    int b[1000001] = {0,};
    int ss=0, tmp =0;
    for (int i=1; i<=na; ++i) {
        cin >> tmp;
        ss += tmp;
        a[i] = ss;
    }
    cin >> nb;
    for (int i=1; i<=nb; ++i) {
        cin >> tmp;
        ss += tmp;
        b[i] = ss;
    }    
    //line segment
    int cnt = 0;

    vector<int> va, vb;
    for (int i=0; i<na; ++i){
        for (int j=i+1; j<=na; ++j ){
            va.push_back(a[j]-a[i]);
        }
    }

    for (int i=0; i<nb; ++i){
        for (int j=i+1; j<=nb; ++j ){
            vb.push_back(b[j]-b[i]);
        }
    }

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    
    ll ans = 0;
    for (int i=0; i<va.size(); ++i){
        if(vb[i] >= T) break;
        for (int j=0; j<vb.size(); ++j){
            if (va[j] + va[i] == T)
                ans++;
            if (va[j] + va[j] > T) break;
        }
    }

    cout << ans << '\n';
}