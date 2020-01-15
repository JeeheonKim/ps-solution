#include <iostream>
#include <queue> //pair
using namespace std;
#define finish(x) return cout << x << endl, 0
#define INF 200000 + 1
#define MAX 200000 + 1

int N, K;
int moves[MAX] ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    
    queue<int> q;
    q.push(N);
    moves[N] = 0;

    for (int i=0; i<MAX; ++i){
        moves[i] = INF;
    }

    while (!q.empty()) {
        int pos = q.front();
        q.pop();
        //cout << pos << "=" << moves[pos]<< endl;

        if (pos == K){ 
            break;}

        if(moves[pos] == INF) moves[pos] = 0;
        
        if (moves[pos+1]==INF  && pos+1 <=MAX) {
            moves[pos+1] = moves[pos] + 1;
            q.push(pos+1);

        }

        if (moves[pos-1] ==INF && pos-1 >=0) {
            moves[pos-1] = moves[pos] + 1;
            q.push(pos-1);

        }


        if (moves[pos*2] ==INF && pos*2<=2*K) {
            moves[pos*2] = moves[pos] + 1;
            q.push(pos*2);

        }
    }

    finish(moves[K]);
}