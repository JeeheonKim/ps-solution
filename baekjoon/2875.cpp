#include <iostream>
using namespace std;

int main(){
    int N = 0; int M = 0; int K = 0;
    cin >> N >> M >> K;
    //남, 여, 인턴쉽
    int p1 = N/2;
    int r = N%2;
    int team = 0;
    if (p1> M){
        r += p1*2 - M;
        team = M;
    } 
    else if (p1 <M) {
        r += M - p1;
        team = p1;
    }
    else {
        team = M;
    }


    if (K>r){
        K -= r;
        while (K!=0){
            if (K<=3){
                team --;
                K = 0;
            } else {
                team -= K/3;
                K %= 3;
            }
        }
    }
    cout << team << endl;
}