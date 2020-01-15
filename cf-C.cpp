#include <iostream>
using namespace std;

long long min(long long a, long long b){
    if (a<b) return a;
    else return b;
}

long long max(long long a, long long b){
    if (a>b) return a;
    else return b;
}

int main(){
    long long N;
    cin >> N;

    // LCM(a,b) == X and a, b should be small!
    long long mn = 1000;

    //easy case
    for (int i=1; i<10; ++i){
        if (N % i == 0){
            mn = min(mn, max(i, (int) N/i))l
        }
    }
}