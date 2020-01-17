//그래프 생각은 했는데 구현할 엄두가 안났음. 다른 코드 참고해서 품.
// 1 3 는 1과 3이 서로를 안다는 뜻이다. 나는 1 3 과 3 1이 다른 줄
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

const int mx = 4000;
bool mp[mx][mx];
int deg[mx] = {0}, a[mx], b[mx], x, y;
int min(int a, int b){
    if (a<b) return a;
    return b;
}

int main(){
    int n, m, ans = -1;
    cin >> n >> m ;
    for (int i=1; i<=m; ++i){
        cin >> a[i] >> b[i];
        deg[a[i]]++;
        deg[b[i]]++;
        mp[a[i]][b[i]] = mp[b[i]][a[i]] = true;
    }    

    for (int i=1; i<=m; ++i) {
        x = a[i]; y = b[i];
        for (int j=1; j<=n; j++) {
            if (j==x || j==y) continue;
            if (mp[x][j] && mp[y][j]) {
                ans = min(ans, deg[x]+deg[y]+deg[j]-6);
            }
        }
    }

    cout << ans <<'\n';
    return 0; 
}