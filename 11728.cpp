#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
cin.tie(static_cast<ostream*>(0));
    int N, M;

    cin >> N >> M;
    int a1[N+1];
    int a2[M+1];

    for (int i=1; i<=N; ++i){
        cin >> a1[i];
    }

    for (int i=1; i<=M; ++i){
        cin >> a2[i];
    }

    int b[M+N+1];
    int cnt1 = 1; int cnt2 = 1;
    for(int i=1; i<=M+N; ++i ){
        if (cnt1 > N){
            b[i] = a2[cnt2]; 
            cnt2++;
            continue;
        }
        
        if (cnt2 > M){
            b[i] = a1[cnt1]; 
            cnt1++;
            continue;
        }
        // -- base case --
        
        if (a1[cnt1] > a2[cnt2]) {
            b[i] = a2[cnt2];
            cnt2++;
        }

        else if (a1[cnt1] < a2[cnt2]) {
            b[i] = a1[cnt1];
            cnt1++;
        }

        else {
            b[i] = a1[cnt1];
            i++;
            b[i] = a2[cnt2];
            cnt1++; cnt2++;
        }
    }

    //print
    for (int j=1; j<=M+N; ++j){
        if (j!= M+N)
            cout << b[j] << " ";
        else
            cout << b[j] << endl;
    }
}
