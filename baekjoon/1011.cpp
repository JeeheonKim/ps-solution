//3
// 0 3 - 3
// 1 5 - 3
// 45 50 4
#include <iostream>
#include <math.h>
using namespace std;
#define ll long long
void solve(ll x, ll y){
    ll ans = 0;
    ll dist = y - x;
    if (dist <=3) {cout << dist << '\n'; return;}
    if (dist == 4) {cout <<dist << '\n'; return;}
    
    ll r = 0; ll tmp=1;
    ll i, t=0;
    
    r =sqrt(dist) ;


    //이 부분 로직..
    if ((r+2)*(r+1) < dist ) r = r+1;
    else if(r*(r+1) > dist) r = r-1;

    ll remainder = dist - (r*(r+1));
    cout << (2*r) + ((remainder > r)? 1 : 0 ) + 1<< endl;
    return;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    ll x, y;
    for (int i=0; i<T; ++i){
        cin >> x >> y;
        solve(x,y);
        //cout << ans << '\n';
    }
    
}